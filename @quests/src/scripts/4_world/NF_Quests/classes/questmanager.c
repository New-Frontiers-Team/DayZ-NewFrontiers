class NF_QuestManager
{
    const string QUESTS_DIR = NF_DIR + "Quests/";

    private ref array<ref NF_QuestNPC> m_NPCs = new ref array<ref NF_QuestNPC>;

    void NF_QuestManager()
    {
        Init();
    }

    private void Init()
    {
        LoadNPCs();
    }

    private void LoadNPCs()
    {
        string fileName;
        FileAttr fileAttr;
        FindFileHandle npcs = FindFile(QUESTS_DIR + "*.json", fileName, fileAttr, FindFileFlags.DIRECTORIES);

        if (!npcs) return;
        LoadNPC(fileName);

        while (FindNextFile(npcs, fileName, fileAttr)) {
            LoadNPC(fileName);
        }

        CloseFindFile(npcs);
    }

    private void LoadNPC(string fileName)
    {
        string filePath = QUESTS_DIR + fileName;

        ref NF_QuestNPCData data;
        JsonFileLoader<NF_QuestNPCData>.JsonLoadFile(filePath, data);

        ref NF_QuestNPC npc = new NF_QuestNPC(data);
        m_NPCs.Insert(npc);
    }

    ref array<ref NF_QuestNPC> GetNPCs()
    {
        return m_NPCs;
    }
}
