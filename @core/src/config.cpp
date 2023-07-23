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
			class worldScriptModule
			{
				value = "";
				files[] = {
					"NewFrontiers/Scripts/4_World",
				};
			};
		};
	};
};