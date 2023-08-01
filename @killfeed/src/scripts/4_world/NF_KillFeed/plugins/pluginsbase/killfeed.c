class NF_KillFeed : PluginBase
{
    void OnPlayerKilled(PlayerBase victim = null, PlayerBase killer = null, EntityAI weapon = null)
    {
        string victimName, killerName, killerWeapon;

        if (victim.GetIdentity() && killer.GetIdentity()) {
            killerName = killer.GetIdentity().GetName();
			victimName = victim.GetIdentity().GetName();

            if (weapon) {
                killerWeapon = weapon.GetType();

                array<Man> players = new array<Man>();
		        GetGame().GetWorld().GetPlayerList(players);

		        foreach (ref Man player: players)
		        {
			        PlayerBase recipient = PlayerBase.Cast(player);
			        if (recipient.IsAlive()) {
                        GetRPCManager().SendRPC("NF_KillFeed", "RPCUpdateKillFeed", new Param3<string, string, string>(killerName, victimName, killerWeapon), true, recipient.GetIdentity());
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