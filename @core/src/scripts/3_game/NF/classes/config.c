static const string NF_DIR = "$profile:NewFrontiers/";

class NF_ConfigData
{
    ref array<ref NF_FactionData> factions = new ref array<ref NF_FactionData>;
}

class NF_Config
{
    static const string CONFIG_FILE = NF_DIR + "config.json";

    private ref NF_ConfigData m_Data;

    void NF_Config()
    {
        Init();
    }

    private void Init()
    {
		if(!FileExist(NF_DIR))
			MakeDirectory(NF_DIR);
		
        if (FileExist(CONFIG_FILE)) {
            Print("[NF] Loading config...");
            LoadConfig();
        } else {
            Print("[NF] Config file not found!");
            m_Data = new NF_ConfigData();
        }
    }

    private void LoadConfig()
    {
        JsonFileLoader<NF_ConfigData>.JsonLoadFile(CONFIG_FILE, m_Data);
    }

    array<ref NF_Faction> GetFactions()
    {
        array<ref NF_Faction> factions = new array<ref NF_Faction>;

        foreach(ref NF_FactionData data: m_Data.factions) {
            ref NF_Faction faction = new NF_Faction(data);
            factions.Insert(faction);
        }

        return factions;
    }
}
