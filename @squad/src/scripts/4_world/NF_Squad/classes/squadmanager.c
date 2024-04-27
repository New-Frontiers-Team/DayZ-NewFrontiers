class NF_SquadManager
{
    private ref array<ref NF_Squad> m_Squads = new ref array<ref NF_Squad>;

    void InvitePlayer(PlayerBase player, PlayerBase invitedPlayer)
    {
        NF_Player nfPlayer = GetNFManager().GetPlayer(player);
        NF_Player nfInvitedPlayer = GetNFManager().GetPlayer(invitedPlayer);
        NF_Squad m_Squad;

        if (!nfPlayer.GetSquad()) {
            m_Squad = new NF_Squad(nfPlayer);
            m_Squads.Insert(m_Squad);
            nfPlayer.JoinSquad(m_Squad);
        } else {
            m_Squad = nfPlayer.GetSquad(); 
        }
        
        m_Squad.InvitePlayer(nfInvitedPlayer, nfPlayer);
    }
}