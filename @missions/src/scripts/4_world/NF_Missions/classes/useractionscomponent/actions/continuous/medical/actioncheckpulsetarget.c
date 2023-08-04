modded class ActionCheckPulseTarget
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        PlayerBase ntarget = PlayerBase.Cast(target.GetObject());
        if (ntarget.NF_IsQuestNPC()) return false;

        return super.ActionCondition(player, target, item);
    }
}
