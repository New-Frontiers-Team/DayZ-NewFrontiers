modded class MissionServer extends MissionBase
{
	void MissionServer()
	{
		GetNewFrontiersManager();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		GetNewFrontiersManager().OnPlayerConnect(player);
		
		super.InvokeOnConnect(player, identity);
	}
	
	override void InvokeOnDisconnect( PlayerBase player )
	{
		GetNewFrontiersManager().OnPlayerDisconnect(player);
		
		super.InvokeOnDisconnect(player);
	}
}