modded class PlayerBase
{
    override void Init()
    {
        super.Init();
    }

    override void SetActionsRemoteTarget(out TInputActionMap InputActionMap)
    {
        super.SetActionsRemoteTarget(InputActionMap);

        AddAction(NF_ActionSquadInvite, InputActionMap);
    }
}