class NF_Bases_SafezoneManager
{
	const float TICK_INTERVAL_SEC = 0.5;
	const float RESTRICTED_AREA_SEC = 30;
	const float SAFEZONE_EXIT_SEC = 15;

	private PlayerBase m_Player;

	private bool m_IsInSafezone;
	private bool m_IsProtected;
	private bool m_ShowAlert;
	private int m_AlertTime;

	private float m_Tick;
	private float m_RestrictedAreaTick;
	private float m_SafezoneExitTick;

	void NF_Bases_SafezoneManager(PlayerBase player)
	{
		m_Player = player;
		m_IsInSafezone = false;
		m_IsProtected = false;
		m_ShowAlert = false;
		m_AlertTime = 0;

		m_Tick = 0;
		m_RestrictedAreaTick = 0;
		m_SafezoneExitTick = 0;

		UpdateGUI();
	}

	void OnScheduledTick(float delta_time)
	{
		m_Tick += delta_time;
		if (m_Tick >= TICK_INTERVAL_SEC) CheckInSafezone();
	}

	void CheckInSafezone()
	{
		bool isProtected = m_IsProtected;

		ref NF_Bases_Safezone safezone = GetNFManager().CheckPlayerInSafezone(m_Player);
		if (safezone) {
			ref NF_Player nfPlayer = m_Player.NF_GetPlayer();
			if (safezone.IsAllowed(nfPlayer) && !m_Player.NF_IsInCombatMode()) {
				isProtected = true;
				m_ShowAlert = false;
				m_RestrictedAreaTick = 0;
			} else {
				isProtected = false;
				m_ShowAlert = true;
				m_RestrictedAreaTick += m_Tick;
			}

			m_SafezoneExitTick = 0;
		} else {
			m_ShowAlert = false;
			m_RestrictedAreaTick = 0;

			if (m_IsInSafezone && m_IsProtected) {
				isProtected = true;
				m_SafezoneExitTick += m_Tick;
			}
		}

		if (m_RestrictedAreaTick >= RESTRICTED_AREA_SEC) {
			m_Player.SetHealth("GlobalHealth", "Health", 0);
		}

		if (m_SafezoneExitTick >= SAFEZONE_EXIT_SEC) {
			isProtected = false;
			m_SafezoneExitTick = 0;
		}

		bool isInSafezone = !!safezone || isProtected;
		if (isInSafezone != m_IsInSafezone) {
			m_IsInSafezone = isInSafezone;
			m_Player.NF_SetIsInSafezone(isInSafezone);
		}

		if (isProtected != m_IsProtected) {
			m_Player.SetAllowDamage(!isProtected);
		}

		int alertTime = (int)(RESTRICTED_AREA_SEC - m_RestrictedAreaTick);
		if (isProtected != m_IsProtected || alertTime != m_AlertTime) {
			m_IsProtected = isProtected;
			m_AlertTime = alertTime;

			UpdateGUI();
		}

		m_Tick = 0;
	}

	bool CheckAllowed(NF_Bases_Safezone safezone)
	{
		ref NF_Player player = m_Player.NF_GetPlayer();
		int reputation = player.GetReputation(safezone.GetFaction());

        return reputation >= safezone.GetMinReputation();
	}

	void UpdateGUI()
	{
		GetRPCManager().SendRPC("NF_Bases", "RPCUpdateSafezoneState", new Param3<bool, bool, int>(m_IsProtected, m_ShowAlert, m_AlertTime), true, m_Player.GetIdentity());
	}
}
