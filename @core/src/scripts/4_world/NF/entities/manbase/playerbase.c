modded class PlayerBase
{
	protected ref NF_Player m_NF_Player;
	protected int m_NF_FactionId;

	protected bool m_NF_IsInCombatMode;
	protected float m_NF_CombatModeTick;
	
	const float NF_COMBAT_MODE_SEC = 60;

	override void Init()
	{
		m_NF_FactionId = 0;
		RegisterNetSyncVariableInt("m_NF_FactionId");
		
		super.Init();
	}
	
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		if(GetGame().IsServer() && GetIdentity()) {
			m_NF_Player = GetNFManager().GetPlayer(GetIdentity().GetId());
			NF_SetFaction(m_NF_Player.GetFaction());
		}
	}
	
	int NF_GetFaction()
	{
		return m_NF_FactionId;
	}
	
	void NF_SetFaction(NF_Faction faction)
	{
		m_NF_FactionId = faction.GetId();

		if(m_NF_FactionId) {
			int slot_id = InventorySlots.GetSlotIdFromString("Armband");
			EntityAI armband = GetInventory().FindAttachment(slot_id);

			if (armband) {
				GetInventory().LocalDestroyEntity(armband);
			}

			if (faction.GetArmband()) {
				GetInventory().CreateAttachmentEx(faction.GetArmband(), slot_id);
				GetInventory().SetSlotLock(slot_id, true);
			}
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
