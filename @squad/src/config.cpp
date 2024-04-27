class CfgPatches
{
	class NewFrontiersSquad
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
	class NewFrontiersSquad
	{
		type = "mod";

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersSquad/scripts/4_world",
				};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiersSquad/scripts/5_mission",
				};
			}
		};
	};
};