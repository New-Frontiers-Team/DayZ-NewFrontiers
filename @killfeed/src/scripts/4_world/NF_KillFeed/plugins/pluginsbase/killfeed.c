class NF_KillFeed : PluginBase
{
    void OnPlayerKilled(PlayerBase victim = null, PlayerBase killer = null, EntityAI weapon = null)
    {
        string victimName, killerName, killerWeapon;
        int victimFaction, killerFaction;

        if (victim.GetIdentity() && killer.GetIdentity()) {
            killerName = killer.GetIdentity().GetName();
            killerFaction = killer.NF_GetFaction();
			victimName = victim.GetIdentity().GetName();
            victimFaction = victim.NF_GetFaction();

            if (weapon) {
                killerWeapon = weapon.GetType();
                int dst = vector.Distance(victim.GetPosition(), killer.GetPosition());

                array<Man> players = new array<Man>();
		        GetGame().GetWorld().GetPlayerList(players);

		        foreach (ref Man player: players)
		        {
			        PlayerBase recipient = PlayerBase.Cast(player);
			        if (recipient.IsAlive()) {
                        GetRPCManager().SendRPC("NF_KillFeed", "RPCUpdateKillFeed", new Param6<string, int, string, int, string, int>(killerName, killerFaction, victimName, victimFaction, killerWeapon, dst), true, recipient.GetIdentity());
                    }
		        }
            }
		}
    }
}

NF_KillFeed NF_GetKillFeed()
{
	return NF_KillFeed.Cast(GetPlugin(NF_KillFeed));
}