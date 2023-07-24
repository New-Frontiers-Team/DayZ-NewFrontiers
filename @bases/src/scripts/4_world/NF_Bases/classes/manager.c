class NF_Bases_Manager
{
    private ref NF_Bases_Config m_NF_Bases_Config;

    void NF_Bases_Manager()
    {
        Init();
    }

    void Init()
    {
        m_NF_Bases_Config = new NF_Bases_Config();
    }
	
	NF_Bases_Respawn GetRespawn(int team)
	{
        ref array<ref NF_Bases_Respawn> teamRespawns = new ref array<ref NF_Bases_Respawn>;

		ref array<ref NF_Bases_Respawn> respawns = m_NF_Bases_Config.GetRespawns();
		for ( int i = 0; i < respawns.Count(); i++ )
        {
			ref NF_Bases_Respawn respawn = respawns.Get(i);
			if (respawn.GetTeam() == team) {
                teamRespawns.Insert(respawn);
			}
		}

        if (teamRespawns.Count()) {
            int index = Math.RandomInt(0, teamRespawns.Count());
            return teamRespawns.Get(index);
        }
		
		return null;
	}
	
	NF_Bases_Safezone CheckPlayerInSafezone(PlayerBase player)
	{
		ref array<ref NF_Bases_Safezone> safezones = m_NF_Bases_Config.GetSafezones();
		
		for ( int i = 0; i < safezones.Count(); i++ )
		{
			ref NF_Bases_Safezone safezone = safezones.Get(i);
			
			float distance = NF_Vector.Distance2D(safezone.GetPosition(), player.GetPosition());
			if (distance <= safezone.GetRadius())
			{
				return safezone;
			}
		}
		
		return null;
	}
}

ref NF_Bases_Manager m_NF_Bases_Manager;
NF_Bases_Manager GetNFBasesManager()
{
    if (!m_NF_Bases_Manager) {
        m_NF_Bases_Manager = new NF_Bases_Manager();
    }

    return m_NF_Bases_Manager;
}
