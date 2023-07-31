modded class PlayerBase
{
	private bool m_NF_Bases_IsInSafezone;
	private ref NF_Bases_SafezoneManager m_NF_Bases_SafezoneManager;

	override void Init()
	{
		m_NF_Bases_IsInSafezone = false;
		RegisterNetSyncVariableBool("m_NF_Bases_IsInSafezone");

		if (GetGame().IsServer()) {
			m_NF_Bases_SafezoneManager = new NF_Bases_SafezoneManager(this);
		}

		super.Init();
	}

	int NF_IsInSafezone()
	{
		return m_NF_Bases_IsInSafezone;
	}

	void NF_SetIsInSafezone(bool isInSafezone)
	{
		if (isInSafezone != m_NF_Bases_IsInSafezone) {
			m_NF_Bases_IsInSafezone = isInSafezone;
			SetSynchDirty();
		}
	}

	override bool CanBeRestrained()
	{
		if (NF_IsInSafezone()) {
			return false;
		}

		return super.CanBeRestrained();
	}

	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);

		if (!IsPlayerSelected() || !IsAlive()) return;
		if (m_NF_Bases_SafezoneManager) m_NF_Bases_SafezoneManager.OnScheduledTick(deltaTime);
	}
}
