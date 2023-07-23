class NewFrontiersPlayerData
{
    int team;
}

class NewFrontiersPlayer : RestCallback
{
	static const string DIR_NEW_FRONTIERS = "$profile:NewFrontiers/";
	static const string DIR_PLAYERS = DIR_NEW_FRONTIERS + "Players/";
	
    private string m_Id;
    private int m_Team;

    void NewFrontiersPlayer(string pId)
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
            m_Team = NewFrontiersTeam.GenerateTeam();

            SaveData();
        }
    }
	
	void LoadData()
	{
        NewFrontiersPlayerData data = new NewFrontiersPlayerData();
		JsonFileLoader<NewFrontiersPlayerData>.JsonLoadFile(DIR_PLAYERS + m_Id + ".json", data);

        m_Team = data.team;
	}

	void SaveData()
	{
        NewFrontiersPlayerData data = new NewFrontiersPlayerData();
        data.team = m_Team;

		JsonFileLoader<NewFrontiersPlayerData>.JsonSaveFile(DIR_PLAYERS + m_Id + ".json", data);
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
