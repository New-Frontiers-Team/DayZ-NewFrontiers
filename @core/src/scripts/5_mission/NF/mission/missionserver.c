modded class MissionServer extends MissionBase
{
	void MissionServer()
	{
		GetNFManager();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		GetNFManager().OnPlayerConnect(player);
		
		super.InvokeOnConnect(player, identity);
	}
	
	override void InvokeOnDisconnect( PlayerBase player )
	{
		GetNFManager().OnPlayerDisconnect(player);
		
		super.InvokeOnDisconnect(player);
	}
}