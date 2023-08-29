modded class MissionServer extends MissionBase
{
	void MissionServer()
	{
		GetNFManager().Init();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		if (identity) {
			GetNFManager().OnPlayerConnect(identity.GetId());
		}

		super.InvokeOnConnect(player, identity);
	}

	override void PlayerDisconnected(PlayerBase player, PlayerIdentity identity, string uid)
	{
		if (uid) {
			GetNFManager().OnPlayerDisconnect(uid);
		}

		super.PlayerDisconnected(player, identity, uid);
	}
}