modded class MissionServer extends MissionBase
{	
	void MissionServer()
	{
		GetNFBasesManager();
	}
	
	override PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx)
	{
		ref NF_Player nf_Player = GetNFManager().GetPlayer(identity.GetId());
		int team = nf_Player.GetTeam();
		
		ref NF_Bases_Respawn respawn = GetNFBasesManager().GetRespawn(team);
		if (respawn) {
			pos = respawn.GetPosition();
		}
		
		return super.OnClientNewEvent(identity, pos, ctx);
	}
}
