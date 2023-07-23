modded class PlayerBase
{
	protected ref NF_Player m_NF_Player;
	protected int m_NF_Team;
	
	override void Init()
	{
		m_NF_Team = 0;
		RegisterNetSyncVariableInt("m_NF_Team", 0, 2);
		
		super.Init();
	}
	
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		if ( GetGame().IsServer() && GetIdentity() )
		{
			m_NF_Player = GetNFManager().GetPlayer(GetIdentity().GetPlainId());
			SetNFTeam(m_NF_Player.GetTeam());
		}
	}
	
	int GetNFTeam()
	{
		return m_NF_Team;
	}
	
	void SetNFTeam( int nf_team )
	{
		m_NF_Team = nf_team;
		Print("[NewFrontiers] Team changed to " + NF_Team.GetTeamName(m_NF_Team));

		int slot_id = InventorySlots.GetSlotIdFromString("Armband");
		EntityAI armband = GetInventory().FindAttachment(slot_id);

		if (armband && (armband.GetType() == "Armband_Blue" || armband.GetType() == "Armband_Red")) {
			GetInventory().LocalDestroyEntity(armband);
		}

		if (m_NF_Team) {
			if (m_NF_Team == NF_Teams.Blufor) {
				GetInventory().CreateAttachmentEx("Armband_Blue", slot_id);
			} else if (m_NF_Team == NF_Teams.Opfor) {
				GetInventory().CreateAttachmentEx("Armband_Red", slot_id);
			}

			GetInventory().SetSlotLock(slot_id, true);
		} else {
			GetInventory().SetSlotLock(slot_id, false);
		}

		SetSynchDirty();
	}
}
