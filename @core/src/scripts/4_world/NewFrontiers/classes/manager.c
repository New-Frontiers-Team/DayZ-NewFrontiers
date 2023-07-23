class NewFrontiersManager
{
    private ref array< ref NewFrontiersPlayer > m_NewFrontiersPlayers = new ref array< ref NewFrontiersPlayer >;

    void NewFrontiersManager()
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
			ref NewFrontiersPlayer newFrontiersPlayer = GetPlayer(player.GetIdentity().GetPlainId());
			newFrontiersPlayer.SaveData();
			
			UnloadPlayer(player.GetIdentity().GetPlainId());
		}
	}

    private NewFrontiersPlayer LoadPlayer( string pId )
    {
        ref NewFrontiersPlayer newFrontiersPlayer = new NewFrontiersPlayer(pId);
        m_NewFrontiersPlayers.Insert(newFrontiersPlayer);

        return newFrontiersPlayer;
    }
	
	private NewFrontiersPlayer UnloadPlayer( string pId )
	{
		for ( int i = 0; i < m_NewFrontiersPlayers.Count(); i++ )
        {
            ref NewFrontiersPlayer newFrontiersPlayer = m_NewFrontiersPlayers.Get(i);
            if ( newFrontiersPlayer.GetPlayerId() == pId )
            {
                m_NewFrontiersPlayers.Remove(i);
				return newFrontiersPlayer;
            }
        }
		
		return null;
	}

    NewFrontiersPlayer GetPlayer( string pId )
    {
        for ( int i = 0; i < m_NewFrontiersPlayers.Count(); i++ )
        {
            ref NewFrontiersPlayer newFrontiersPlayer = m_NewFrontiersPlayers.Get(i);
            if ( newFrontiersPlayer.GetPlayerId() == pId )
            {
                return newFrontiersPlayer;
            }
        }

        return LoadPlayer(pId);
    }
}

ref NewFrontiersManager m_NewFrontiersManager;
NewFrontiersManager GetNewFrontiersManager()
{
    if (!m_NewFrontiersManager) {
        m_NewFrontiersManager = new NewFrontiersManager();
    }

    return m_NewFrontiersManager;
}
