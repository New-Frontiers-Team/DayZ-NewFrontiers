class CfgPatches
{
	class NewFrontiersKillFeed
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"NewFrontiers",
		};
	};
};

class CfgMods
{
	class NewFrontiersKillFeed
	{
		type = "mod";

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersKillFeed/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersKillFeed/scripts/5_mission",
				};
			}
		};
	};
};