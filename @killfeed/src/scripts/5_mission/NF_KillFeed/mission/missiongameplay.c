modded class MissionGameplay
{
    private ref NF_KillFeedWrapper m_KillFeed;

	void MissionGameplay()
	{
		m_KillFeed = new NF_KillFeedWrapper();

		GetRPCManager().AddRPC("NF_KillFeed", "RPCUpdateKillFeed", this, SingeplayerExecutionType.Both);
	}

	void RPCUpdateKillFeed(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param6<string, int, string, int, string, int> data;
		if (!ctx.Read(data)) return;

		m_KillFeed.AddItem(data);
	}
}
