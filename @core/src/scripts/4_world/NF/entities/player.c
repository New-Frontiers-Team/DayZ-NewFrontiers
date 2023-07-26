class NF_PlayerData
{
    int team;
}

class NF_Player : RestCallback
{
	static const string DIR_NEW_FRONTIERS = "$profile:NewFrontiers/";
	static const string DIR_PLAYERS = DIR_NEW_FRONTIERS + "Players/";
	
    private string m_Id;
    private int m_Team;

    private string m_FilePath;

    void NF_Player(string uid)
    {
        m_Id = uid;
        m_Team = 0;

        m_FilePath = DIR_PLAYERS + NF_String.FileReadyName(uid) + ".json";

        Init();
    }

    void Init()
    {
		if(!FileExist(DIR_NEW_FRONTIERS))
			MakeDirectory(DIR_NEW_FRONTIERS);
		
        if(!FileExist(DIR_PLAYERS))
			MakeDirectory(DIR_PLAYERS);

        if(FileExist(m_FilePath)) {
            LoadData();
        } else {
            m_Team = NF_Team.GenerateTeam();

            SaveData();
        }
    }
	
	void LoadData()
	{
        NF_PlayerData data = new NF_PlayerData();
		JsonFileLoader<NF_PlayerData>.JsonLoadFile(m_FilePath, data);

        m_Team = data.team;
	}

	void SaveData()
	{
        NF_PlayerData data = new NF_PlayerData();
        data.team = m_Team;

		JsonFileLoader<NF_PlayerData>.JsonSaveFile(m_FilePath, data);
	}
	
	string GetId()
	{
		return m_Id;
	}

    int GetTeam()
    {
        return m_Team;
    }
}
