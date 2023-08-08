modded class MissionServer
{
    void MissionServer()
    {
        GetRPCManager().AddRPC("NF_Quests", "NF_RPCRequestQuestNPCData", this, SingeplayerExecutionType.Server);
    }

    void NF_RPCRequestQuestNPCData(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<int> data;
        if (!ctx.Read(data)) return;

        int npcId = data.param1;
        if (!npcId) return;

        ref NF_QuestNPC npc = GetNFManager().GetQuestNPC(npcId);
        if (!npc) return;

        GetRPCManager().SendRPC("NF_Quests", "NF_RPCGetQuestNPCData", new Param2<int, ref NF_QuestNPC>(npcId, npc), true, sender);
    }
}
