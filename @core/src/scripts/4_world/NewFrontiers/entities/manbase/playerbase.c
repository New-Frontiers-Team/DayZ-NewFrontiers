modded class PlayerBase
{
	protected ref NewFrontiersPlayer m_NewFrontiersPlayer;
	protected int m_NewFrontiersTeam;
	
	override void Init()
	{
		m_NewFrontiersTeam = 0;
		RegisterNetSyncVariableInt("m_NewFrontiersTeam", 0, 2);
		
		super.Init();
	}
	
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		if ( GetGame().IsServer() && GetIdentity() )
		{
			m_NewFrontiersPlayer = GetNewFrontiersManager().GetPlayer(GetIdentity().GetPlainId());
			SetNewFrontiersTeam(m_NewFrontiersPlayer.GetTeam());
		}
	}
	
	int GetNewFrontiersTeam()
	{
		return m_NewFrontiersTeam;
	}
	
	void SetNewFrontiersTeam( int newFrontiers_team )
	{
		m_NewFrontiersTeam = newFrontiers_team;
		Print("[NewFrontiers] Team changed to " + NewFrontiersTeam.GetTeamName(m_NewFrontiersTeam));

		int slot_id = InventorySlots.GetSlotIdFromString("Armband");
		EntityAI armband = GetInventory().FindAttachment(slot_id);

		if (armband && (armband.GetType() == "Armband_Blue" || armband.GetType() == "Armband_Red")) {
			GetInventory().LocalDestroyEntity(armband);
		}

		if (m_NewFrontiersTeam) {
			if (m_NewFrontiersTeam == NewFrontiersTeams.Blufor) {
				GetInventory().CreateAttachmentEx("Armband_Blue", slot_id);
			} else if (m_NewFrontiersTeam == NewFrontiersTeams.Opfor) {
				GetInventory().CreateAttachmentEx("Armband_Red", slot_id);
			}

			GetInventory().SetSlotLock(slot_id, true);
		} else {
			GetInventory().SetSlotLock(slot_id, false);
		}

		SetSynchDirty();
	}
}
