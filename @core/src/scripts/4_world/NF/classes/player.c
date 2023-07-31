class NF_Player : RestCallback
{
	static const string DIR_PLAYERS = NF_DIR + "Players/";
    private string m_FilePath;

    private string m_Id;
    private NF_Faction m_Faction;
    private ref map<int, int> m_Reputation;

    void NF_Player(string uid)
    {
        m_Id = uid;
        m_FilePath = DIR_PLAYERS + NF_String.FileReadyName(uid) + ".json";

        Init();
    }

    void Init()
    {
        if (!FileExist(DIR_PLAYERS))
			MakeDirectory(DIR_PLAYERS);

        if (FileExist(m_FilePath)) {
            LoadData();
        } else {
            InitData();
        }
    }

	void LoadData()
	{
        NF_PlayerData data = new NF_PlayerData();
		JsonFileLoader<NF_PlayerData>.JsonLoadFile(m_FilePath, data);

        m_Faction = GetNFManager().GetFaction(data.faction);
        m_Reputation = data.reputation;
	}

    void InitData()
    {
        m_Faction = GetNFManager().GetFaction(0);
        m_Reputation = new map<int, int>;

        SaveData();
    }

	void SaveData()
	{
        NF_PlayerData data = new NF_PlayerData();
        data.faction = m_Faction.GetId();
        data.reputation = m_Reputation;

		JsonFileLoader<NF_PlayerData>.JsonSaveFile(m_FilePath, data);
	}

	string GetId()
	{
		return m_Id;
	}

    NF_Faction GetFaction()
    {
        return m_Faction;
    }

	int GetReputation(int factionId)
	{
		int currentReputation;
		if (m_Reputation.Find(factionId, currentReputation)) {
			return currentReputation;
		}

		return 0;
	}

	void GainReputation(int factionId, int value)
	{
		int currentReputation = GetReputation(factionId);
		m_Reputation.Set(factionId, currentReputation + value);
	}

	void LoseReputation(int factionId, int value)
	{
		int currentReputation = GetReputation(factionId);
		m_Reputation.Set(factionId, currentReputation - value);
	}
}
