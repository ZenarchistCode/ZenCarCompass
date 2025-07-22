class ZenCarCompass extends Compass
{
	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();

		// Item is scope=1 so this shouldn't be persistent, but in case I'm wrong, 
		// delete it after restarts as EEItemAttached() creates a new one in CarScript.
		DeleteSafe();
	}

	override void DeferredInit()
	{
		super.DeferredInit();

		SetAllowDamage(false);
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool IsInventoryVisible()
	{
		return false;
	}

	override bool CanDisplayCargo()
	{
		return false;
	}

	override bool IsTakeable()
	{
		return false;
	}

	override bool DisableVicinityIcon()
	{
		return true;
	}

	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{ 
		super.OnItemLocationChanged(old_owner, new_owner);

		if (!new_owner || !new_owner.IsInherited(CarScript))
		{
			DeleteSafe();
		}
	}
}