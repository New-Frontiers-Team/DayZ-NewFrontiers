class CfgPatches
{
	class NewFrontiersQuests
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
	class NewFrontiersQuests
	{
		type = "mod";

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersQuests/scripts/3_game",
				};
			}
			class worldScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersQuests/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersQuests/scripts/5_mission",
				};
			}
		};
	};
};