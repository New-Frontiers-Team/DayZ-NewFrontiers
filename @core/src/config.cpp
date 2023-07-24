class CfgPatches
{
	class NewFrontiers
	{
		requiredAddons[] = {
			"JM_CF_Scripts",
		};
	};
};

class CfgMods
{
	class NewFrontiers
	{
		type = "mod";

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiers/scripts/3_game",
				};
			}

			class worldScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiers/scripts/4_world",
				};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiers/scripts/5_mission",
				};
			}
		};
	};
};