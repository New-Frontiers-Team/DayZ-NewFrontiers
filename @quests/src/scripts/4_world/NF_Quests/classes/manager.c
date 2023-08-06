modded class NF_Manager
{
    private ref array<ref NF_QuestNPC> m_QuestNPCs;

    void NF_Manager()
    {
        m_QuestNPCs = new ref array<ref NF_QuestNPC>
    }

    override void Init()
    {
        super.Init();

        NF_QuestManager questManager = new NF_QuestManager();
        m_QuestNPCs = questManager.GetNPCs();
    }
}
