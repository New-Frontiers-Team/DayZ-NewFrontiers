modded class PlayerBase
{
	override void EEKilled(Object killer)
	{
		EntityAI weapon = EntityAI.Cast(killer);
		PlayerBase pKiller = PlayerBase.Cast(weapon.GetHierarchyRootPlayer());

		if (pKiller && pKiller != this) {
			NF_GetKillFeed().OnPlayerKilled(this, pKiller, weapon);
		}

		super.EEKilled(killer);
	}
}