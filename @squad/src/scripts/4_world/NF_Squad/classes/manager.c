modded class NF_Manager
{
    private ref NF_SquadManager m_SquadManager;

    override void Init()
    {
        super.Init();
        m_SquadManager = new NF_SquadManager();
    }

    ref NF_SquadManager GetSquadManager()
    {
        return m_SquadManager;
    }
}