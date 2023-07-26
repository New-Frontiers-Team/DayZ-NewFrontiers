modded class PlayerBase
{
	protected ref NF_Player m_NF_Player;
	protected int m_NF_Team;

	protected bool m_NF_IsInCombatMode;
	protected float m_NF_CombatModeTick;
	
	const float NF_COMBAT_MODE_SEC = 60;

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
			m_NF_Player = GetNFManager().GetPlayer(GetIdentity().GetId());
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

	void NF_SetCombatMode() {
		m_NF_IsInCombatMode = true;
		m_NF_CombatModeTick = 0;
	}

	bool NF_IsInCombatMode() {
		return m_NF_IsInCombatMode;
	}

	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		
		if( !IsPlayerSelected() || !IsAlive() ) return;
		if( m_NF_IsInCombatMode ) m_NF_CombatModeTick += deltaTime;

		if (m_NF_CombatModeTick >= NF_COMBAT_MODE_SEC) {
			m_NF_IsInCombatMode = false;
			m_NF_CombatModeTick = 0;
		}
	}
}
