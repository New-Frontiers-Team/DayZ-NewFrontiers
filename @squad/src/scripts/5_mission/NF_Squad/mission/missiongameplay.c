modded class MissionGameplay
{
    private ref NF_Squad_InviteUI m_NF_Squad_InviteUI;
    private string m_NF_Squad_Inviter;

    void MissionGameplay()
    {
        m_NF_Squad_InviteUI = new NF_Squad_InviteUI();

        GetRPCManager().AddRPC("NF_Squad", "RPCSquadInvite", this, SingleplayerExecutionType.Both);
    }

    void RPCSquadInvite(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        Param1<string> data;
        if (!ctx.Read(data)) return;

        m_NF_Squad_Inviter = data.param1;

        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "NF_SquadInvite");
    }
	
	void NF_SquadInvite()
    {
        if (!m_NF_Squad_InviteUI) return;

        m_NF_Squad_InviteUI.Invite(m_NF_Squad_Inviter);
    }
}