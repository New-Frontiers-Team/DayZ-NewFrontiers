class NF_Config
{
    static const string CONFIG_FILE = NF_DIR + "config.json";

    private ref NF_ConfigData m_Data;
    ref array<ref NF_Faction> m_Factions = new ref array<ref NF_Faction>;

    void NF_Config()
    {
        Init();
    }

    private void Init()
    {
        m_Factions = new ref array<ref NF_Faction>;

		if (!FileExist(NF_DIR))
			MakeDirectory(NF_DIR);

        if (FileExist(CONFIG_FILE)) {
            Print("[NF] Loading config...");
            LoadConfig();
        } else {
            Print("[NF] Config file not found!");
        }
    }

    private void LoadConfig()
    {
        ref NF_ConfigData data
        JsonFileLoader<NF_ConfigData>.JsonLoadFile(CONFIG_FILE, data);

        foreach (ref NF_FactionData factionData: data.factions) {
            ref NF_Faction faction = new NF_Faction(factionData);
            m_Factions.Insert(faction);
        }
    }

    ref array<ref NF_Faction> GetFactions()
    {
        return m_Factions;
    }
}
