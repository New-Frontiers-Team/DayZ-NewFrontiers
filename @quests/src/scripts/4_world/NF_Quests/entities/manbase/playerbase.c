modded class PlayerBase
{
    private int m_NF_QuestNPCId;

    override void Init()
    {
        m_NF_QuestNPCId = 0;
        RegisterNetSyncVariableInt("m_NF_QuestNPCId");

        super.Init();
    }

    override void SetActionsRemoteTarget(out TInputActionMap InputActionMap)
    {
        super.SetActionsRemoteTarget(InputActionMap);

        AddAction(NF_ActionTalkTo, InputActionMap);
    }

    bool NF_IsQuestNPC()
    {
        return !!m_NF_QuestNPCId;
    }

    int NF_GetQuestNPCId()
    {
        return m_NF_QuestNPCId;
    }

    void NF_SetQuestNPCId(int id)
    {
        m_NF_QuestNPCId = id;
        SetAllowDamage(!id);
    }
}
