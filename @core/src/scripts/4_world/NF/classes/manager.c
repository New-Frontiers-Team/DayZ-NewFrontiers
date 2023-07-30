class NF_Manager
{
    private ref array<ref NF_Faction> m_Factions = new ref array<ref NF_Faction>;
    private ref array<ref NF_Player> m_Players = new ref array<ref NF_Player>;

    void NF_Manager()
    {
        Print("[NF] Starting...");
        Init();
    }

    private void Init()
    {
        NF_Config config = new NF_Config();
        m_Factions = config.GetFactions();
    }

	void OnPlayerConnect(string uid)
	{
        ref NF_Player nfPlayer = GetPlayer(uid);
        Print("[NF] Player connected " + nfPlayer.GetId());
	}

	void OnPlayerDisconnect(string uid)
	{
        ref NF_Player nfPlayer = GetPlayer(uid);
        nfPlayer.SaveData();
        UnloadPlayer(uid);

        Print("[NF] Player disconnected " + nfPlayer.GetId());
	}

    NF_Player GetPlayer(string uid)
    {
        foreach (ref NF_Player nfPlayer: m_Players) {
            if (nfPlayer.GetId() == uid) {
                return nfPlayer;
            }
        }

        return LoadPlayer(uid);
    }

    private NF_Player LoadPlayer(string uid)
    {
        ref NF_Player nfPlayer = new NF_Player(uid);
        m_Players.Insert(nfPlayer);

        return nfPlayer;
    }

	private NF_Player UnloadPlayer(string uid)
	{
		foreach (int i, ref NF_Player nfPlayer: m_Players) {
            if (nfPlayer.GetId() == uid) {
                m_Players.Remove(i);
				return nfPlayer;
            }
        }

		return null;
	}

    array<ref NF_Faction> GetFactions()
    {
        return m_Factions;
    }

    NF_Faction GetFaction(int id)
    {
        foreach (ref NF_Faction faction: m_Factions) {
            if (faction.GetId() == id) return faction;
        }

        return null;
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
