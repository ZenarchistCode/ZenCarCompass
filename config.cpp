class CfgPatches
{
	class ZenCarCompass
	{
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Navigation",
			"DZ_Vehicles_Wheeled"
		};
	};
};

class CfgMods
{
	class ZenCarCompass
	{
		dir = "ZenCarCompass";
		name = "Zen's Swiss Knife";
		author = "Zenarchist";
		credits = "";
		version = "1.0";
		type = "mod";
		dependencies[] = 
		{ 
			"Game", 
			"World", 
			"Mission" 
		};
		class defs
		{
			class imageSets
			{
				files[] =
				{
					// Taken from ZenModPack... few extra icons in here but whatever.
					"ZenCarCompass/data/gui/journal/zenjournal.imageset"
				};
			};
			class engineScriptModule
			{
				files[]=
				{
					//"ZenCarCompass/scripts/1_Core",
					"ZenCarCompass/scripts/Common"
				};
			};
			class gameLibScriptModule
			{
				files[]=
				{
					//"ZenCarCompass/scripts/2_GameLib",
					"ZenCarCompass/scripts/Common"
				};
			};
			class gameScriptModule
			{
				files[] = 
				{ 
					"ZenCarCompass/scripts/Common",
					"ZenCarCompass/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[] = 
				{ 
					"ZenCarCompass/scripts/Common",
					"ZenCarCompass/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				files[] = 
				{ 
					"ZenCarCompass/scripts/Common",
					"ZenCarCompass/scripts/5_mission"
				};
			};
		};
	};
};

class CfgVehicles
{
	//! PRELOAD 
	class Truck_01_Base;
	class ItemCompass;
	class CarScript;

	//! VANILLA ITEM OVERRIDES
	class Compass: ItemCompass
	{
		inventorySlot[] +=
		{
			"ZenJournal_Compass"
		};
	};

	//! ZEN CAR COMPASS
	class ZenCarCompass : Compass 
	{
		scope = 1;
	};

	//! VANILLA CAR OVERRIDES
	class OffroadHatchback : CarScript
	{
		attachments[] +=
		{
			"ZenJournal_Compass"
		};
		class GUIInventoryAttachmentsProps
		{
			class ZenInterior
			{
				name = "$STR_CfgVehicles_Compass0";
				description = "$STR_CfgVehicles_Compass0";
				icon = "ZenJournal_Compass";
				attachmentSlots[] = 
				{
					"ZenJournal_Compass"
				};
			};				
		};
	};
	class Offroad_02 : CarScript
	{
		attachments[] +=
		{
			"ZenJournal_Compass"
		};
		class GUIInventoryAttachmentsProps
		{
			class ZenInterior
			{
				name = "$STR_CfgVehicles_Compass0";
				description = "$STR_CfgVehicles_Compass0";
				icon = "ZenJournal_Compass";
				attachmentSlots[] = 
				{
					"ZenJournal_Compass"
				};
			};				
		};
	};
	class CivilianSedan : CarScript
	{
		attachments[] +=
		{
			"ZenJournal_Compass"
		};
		class GUIInventoryAttachmentsProps
		{
			class ZenInterior
			{
				name = "$STR_CfgVehicles_Compass0";
				description = "$STR_CfgVehicles_Compass0";
				icon = "ZenJournal_Compass";
				attachmentSlots[] = 
				{
					"ZenJournal_Compass"
				};
			};				
		};
	};
	class Hatchback_02 : CarScript
	{
		attachments[] +=
		{
			"ZenJournal_Compass"
		};
		class GUIInventoryAttachmentsProps
		{
			class ZenInterior
			{
				name = "$STR_CfgVehicles_Compass0";
				description = "$STR_CfgVehicles_Compass0";
				icon = "ZenJournal_Compass";
				attachmentSlots[] = 
				{
					"ZenJournal_Compass"
				};
			};				
		};
	};
	class Sedan_02 : CarScript
	{
		attachments[] +=
		{
			"ZenJournal_Compass"
		};
		class GUIInventoryAttachmentsProps
		{
			class ZenInterior
			{
				name = "$STR_CfgVehicles_Compass0";
				description = "$STR_CfgVehicles_Compass0";
				icon = "ZenJournal_Compass";
				attachmentSlots[] = 
				{
					"ZenJournal_Compass"
				};
			};				
		};
	};
	class Truck_01_Covered: Truck_01_Base
	{
		attachments[] +=
		{
			"ZenJournal_Compass"
		};
		class GUIInventoryAttachmentsProps
		{
			class ZenInterior
			{
				name = "$STR_CfgVehicles_Compass0";
				description = "$STR_CfgVehicles_Compass0";
				icon = "ZenJournal_Compass";
				attachmentSlots[] = 
				{
					"ZenJournal_Compass"
				};
			};				
		};
	};
};

class CfgSlots
{
	class Slot_ZenJournal_Compass
	{
		name = "ZenJournal_Compass";
		displayName = "$STR_CfgVehicles_Compass0";
		ghostIcon = "set:zenjournal image:compassicon";
	};
};