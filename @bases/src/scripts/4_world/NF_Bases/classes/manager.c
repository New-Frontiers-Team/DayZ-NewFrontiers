modded class NF_Manager
{
    NF_Bases_Safezone CheckPlayerInSafezone(PlayerBase player)
	{
        foreach (ref NF_Faction faction: m_Factions) {
            foreach (ref NF_Bases_Safezone safezone: faction.GetSafezones()) {
                if (safezone.IsInside(player.GetPosition())) {
                    return safezone;
                }
            }
        }

		return null;
	}
}