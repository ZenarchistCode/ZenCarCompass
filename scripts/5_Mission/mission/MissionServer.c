modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		// Preload config on server startup
		GetZenCarCompassConfig();
	}
}