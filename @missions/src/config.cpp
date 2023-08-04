class CfgPatches
{
    class NewFrontiersMissions
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
    class NewFrontiersMissions
    {
        type = "mod";

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {
                    "NewFrontiersMissions/scripts/4_world",
                };
            }

            class missionScriptModule
            {
                value = "";
                files[] = {
                    "NewFrontiersMissions/scripts/5_mission",
                };
            }
        };
    };
};
