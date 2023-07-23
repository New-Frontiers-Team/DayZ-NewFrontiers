class CfgPatches
{
	class NewFrontiersBases
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
	class NewFrontiersBases
	{
		type = "mod";

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersBases/scripts/3_game",
				};
			}
			class worldScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersBases/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersBases/scripts/5_mission",
				};
			}
		};
	};
};