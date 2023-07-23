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

    void NF_Player(string pId)
    {
        m_Id = pId;
        m_Team = 0;

        Init();
    }

    void Init()
    {
		if(!FileExist(DIR_NEW_FRONTIERS))
			MakeDirectory(DIR_NEW_FRONTIERS);
		
        if(!FileExist(DIR_PLAYERS))
			MakeDirectory(DIR_PLAYERS);

        if(FileExist(DIR_PLAYERS + m_Id + ".json")) {
            LoadData();
        } else {
            m_Team = NF_Team.GenerateTeam();

            SaveData();
        }
    }
	
	void LoadData()
	{
        NF_PlayerData data = new NF_PlayerData();
		JsonFileLoader<NF_PlayerData>.JsonLoadFile(DIR_PLAYERS + m_Id + ".json", data);

        m_Team = data.team;
	}

	void SaveData()
	{
        NF_PlayerData data = new NF_PlayerData();
        data.team = m_Team;

		JsonFileLoader<NF_PlayerData>.JsonSaveFile(DIR_PLAYERS + m_Id + ".json", data);
	}
	
	string GetPlayerId()
	{
		return m_Id;
	}

    int GetTeam()
    {
        return m_Team;
    }
}
