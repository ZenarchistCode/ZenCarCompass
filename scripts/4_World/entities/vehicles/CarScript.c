modded class CarScript
{
	protected ZenCarCompass m_ZenCompassDashboard;

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (GetGame().IsDedicatedServer())
		{
			if (slot_name == "ZenJournal_Compass")
			{
				CreateZenCompass(Compass.Cast(item));
			}
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (GetGame().IsDedicatedServer())
		{
			if (slot_name == "ZenJournal_Compass")
			{
				if (m_ZenCompassDashboard)
				{
					DeleteZenCompass(item);
				}
			}
		}		
	}

	ZenCarCompass GetZenCarCompass()
	{
		return m_ZenCompassDashboard;
	}

	void CreateZenCompass(Compass item)
	{
		if (!GetGame().IsDedicatedServer())
			return;

		if (!item || !item.IsInherited(ItemCompass))
			return;

		bool cfgFound = false;
		vector offsetPos;
		vector offsetOri;

		for (int i = 0; i < GetZenCarCompassConfig().CarConfig.Count(); i++)
		{
			if (this.IsKindOf(GetZenCarCompassConfig().CarConfig.Get(i).CarType))
			{
				cfgFound = true;
				offsetPos = GetZenCarCompassConfig().CarConfig.Get(i).Position;
				offsetOri = GetZenCarCompassConfig().CarConfig.Get(i).Orientation;
				break;
			}
		}

		if (!cfgFound)
		{
			Print("[ZenModPack] Compass attached to car: " + GetType() + " - but this modded car has no offset position config.");
			return;
		}

		if (!m_ZenCompassDashboard)
		{
			m_ZenCompassDashboard = ZenCarCompass.Cast(GetGame().CreateObject("ZenCarCompass", vector.Zero));

			if (!m_ZenCompassDashboard)
			{
				Error("[ZenModPack] Couldn't create duplicate proxy of ZenCarCompass for some reason?");
				return;
			}
		}

		if (!AddChild(m_ZenCompassDashboard, -1, false))
		{
			Error("[ZenModPack] Failed to attach " + m_ZenCompassDashboard.GetType() + " as child to " + GetType() + " for some reason?");
			m_ZenCompassDashboard.DeleteSafe();
			return;
		}

		m_ZenCompassDashboard.SetPosition(offsetPos);
		m_ZenCompassDashboard.SetOrientation(offsetOri);
		m_ZenCompassDashboard.Open();
		m_ZenCompassDashboard.Update();
		m_ZenCompassDashboard.SetHealth(item.GetHealth());
		m_ZenCompassDashboard.SetSynchDirty();

		item.Open();
		item.SetZenCarCompass(m_ZenCompassDashboard);
	}

	void DeleteZenCompass(EntityAI item)
	{
		this.RemoveChild(m_ZenCompassDashboard);
		m_ZenCompassDashboard.DeleteSafe();
		m_ZenCompassDashboard = NULL;

		Compass compassItem = Compass.Cast(item);
		if (compassItem)
		{
			compassItem.SetZenCarCompass(NULL);
		}
	}
}