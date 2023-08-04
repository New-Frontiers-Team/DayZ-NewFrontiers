modded class PlayerBase
{
    private bool m_NF_IsQuestNPC;

    override void Init()
    {
        m_NF_IsQuestNPC = false;
        RegisterNetSyncVariableBool("m_NF_IsQuestNPC");

        super.Init();
    }

    override void SetActionsRemoteTarget(out TInputActionMap InputActionMap)
    {
        super.SetActionsRemoteTarget(InputActionMap);

        AddAction(NF_ActionTalkTo, InputActionMap);
    }

    bool NF_IsQuestNPC()
    {
        return m_NF_IsQuestNPC;
    }

    void NF_SetIsQuestNPC(bool isQuestNPC)
    {
        SetAllowDamage(!isQuestNPC);
        m_NF_IsQuestNPC = isQuestNPC;
    }
}
