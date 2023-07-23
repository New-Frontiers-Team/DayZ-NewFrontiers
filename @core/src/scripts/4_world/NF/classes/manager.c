class NF_Manager
{
    private ref array< ref NF_Player > m_NF_Players = new ref array< ref NF_Player >;

    void NF_Manager()
    {
        Init();
    }

    void Init()
    {
        //GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLaterByName(instance, "SaveNewFrontiersPlayers", 300 * 1000, true);
    }

	void OnPlayerConnect(PlayerBase player)
	{
		if ( player.GetIdentity() ) {
			GetPlayer(player.GetIdentity().GetPlainId());
		}
	}
	
	void OnPlayerDisconnect(PlayerBase player)
	{
		if ( player.GetIdentity() ) {
			ref NF_Player nfPlayer = GetPlayer(player.GetIdentity().GetPlainId());
			nfPlayer.SaveData();
			
			UnloadPlayer(player.GetIdentity().GetPlainId());
		}
	}

    private NF_Player LoadPlayer( string pId )
    {
        ref NF_Player nfPlayer = new NF_Player(pId);
        m_NF_Players.Insert(nfPlayer);

        return nfPlayer;
    }
	
	private NF_Player UnloadPlayer( string pId )
	{
		for ( int i = 0; i < m_NF_Players.Count(); i++ )
        {
            ref NF_Player nfPlayer = m_NF_Players.Get(i);
            if ( nfPlayer.GetPlayerId() == pId )
            {
                m_NF_Players.Remove(i);
				return nfPlayer;
            }
        }
		
		return null;
	}

    NF_Player GetPlayer( string pId )
    {
        for ( int i = 0; i < m_NF_Players.Count(); i++ )
        {
            ref NF_Player nfPlayer = m_NF_Players.Get(i);
            if ( nfPlayer.GetPlayerId() == pId )
            {
                return nfPlayer;
            }
        }

        return LoadPlayer(pId);
    }
}

ref NF_Manager m_NF_Manager;
NF_Manager GetNFManager()
{
    if (!m_NF_Manager) {
        m_NF_Manager = new NF_Manager();
    }

    return m_NF_Manager;
}
