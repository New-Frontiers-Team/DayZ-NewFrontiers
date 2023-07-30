modded class NF_FactionData
{
    ref array<ref NF_Bases_RespawnData> respawns;
    ref array<ref NF_Bases_SafezoneData> safezones;
}

modded class NF_Faction
{
    private ref array<ref NF_Bases_Respawn> m_respawns = new ref array<ref NF_Bases_Respawn>;
    private ref array<ref NF_Bases_Safezone> m_safezones = new ref array<ref NF_Bases_Safezone>;

    void NF_Faction(NF_FactionData data)
    {
        foreach(ref NF_Bases_RespawnData respawn: data.respawns) {
            m_respawns.Insert(new NF_Bases_Respawn(respawn));
        }

        foreach(ref NF_Bases_SafezoneData safezone: data.safezones) {
            m_safezones.Insert(new NF_Bases_Safezone(safezone, m_Id));
        }
    }

    array<ref NF_Bases_Respawn> GetRespawns()
    {
        return m_respawns;
    }

    array<ref NF_Bases_Safezone> GetSafezones()
    {
        return m_safezones;
    }

    NF_Bases_Respawn GetRandomRespawn()
    {
        if(m_respawns.Count() == 0) {
            return null;
        }

        ref NF_Bases_Respawn respawn = m_respawns.Get(Math.RandomInt(0, m_respawns.Count()));
		return respawn;
    }
}
