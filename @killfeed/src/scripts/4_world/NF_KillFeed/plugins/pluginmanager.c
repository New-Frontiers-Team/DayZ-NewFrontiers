modded class PluginManager
{
    override void Init()
    {
        super.Init();

        RegisterPlugin("NF_KillFeed", false, true);
    }
}