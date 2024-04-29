class NF_Squad
{
    private ref array<ref NF_Player> m_Players = new ref array<ref NF_Player>;
    private ref array<ref NF_Player> m_InvitedPlayers = new ref array<ref NF_Player>;

    void NF_Squad(ref NF_Player player)
    {
        m_Players.Insert(player);
    }

    void InvitePlayer(ref NF_Player player, ref NF_Player inviter) {
        m_InvitedPlayers.Insert(player);

        string inviterName = inviter.GetPlayerBase().GetIdentity().GetName();
        
        GetRPCManager().SendRPC("NF_Squad", "RPCSquadInvite", new Param1<string>(inviterName), true, player.GetPlayerBase().GetIdentity());
    }
}