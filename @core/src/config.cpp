class CfgPatches
{
	class NewFrontiers
	{
		requiredAddons[] = {};
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