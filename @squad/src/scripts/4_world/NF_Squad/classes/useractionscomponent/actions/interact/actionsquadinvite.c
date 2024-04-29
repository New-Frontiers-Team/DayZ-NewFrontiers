class NF_ActionSquadInvite: ActionInteractBase
{
    void NF_ActionSquadInvite()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_Text = "#nf_squad_invite";
    }

    override void CreateConditionComponents()
    {
        m_ConditionTarget = new CCTObject(10);
        m_ConditionItem = new CCINone;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (GetGame().IsServer()) return true;

        PlayerBase ntarget = PlayerBase.Cast(target.GetObject());
        if (!ntarget) return false;

        if (ntarget.GetIdentity() != null) {
            ref NF_Player nfPlayer = GetNFManager().GetPlayer(ntarget);
            if (!nfPlayer.GetSquad()) {
                return true;
            }
        }

        return false;
    }
    
    override void OnExecuteServer(ActionData action_data)
    {
        Print("[NF_Squad] Interaction started!");
        PlayerBase player = action_data.m_Player;
		PlayerBase invitedPlayer = PlayerBase.Cast(action_data.m_Target.GetObject());
				
        GetNFManager().GetSquadManager().InvitePlayer(player, invitedPlayer);
    }
}