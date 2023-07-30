modded class MissionServer extends MissionBase
{
	override PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx)
	{
		ref NF_Player nf_Player = GetNFManager().GetPlayer(identity.GetId());
		ref NF_Bases_Respawn respawn = nf_Player.GetFaction().GetRandomRespawn();
		if (respawn) {
			pos = respawn.GetRandomPosition();
		}

		return super.OnClientNewEvent(identity, pos, ctx);
	}
}
