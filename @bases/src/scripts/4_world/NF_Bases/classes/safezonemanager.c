class NF_Bases_SafezoneManager
{
	const float TICK_INTERVAL_SEC = 0.5;
	const float RESTRICTED_AREA_SEC = 30;
	
	private PlayerBase m_Player;
	
	private float m_Tick;
	private float m_RestrictedAreaTick;
	
	private bool m_IsInSafezone;
	private bool m_ShowAlert;
	private int m_AlertTime;
	
	void NF_Bases_SafezoneManager(PlayerBase player)
	{
		m_Player = player;
		m_IsInSafezone = false;
		m_ShowAlert = false;
		m_AlertTime = 0;
		
		UpdateGUI();
	}
	
	void OnScheduledTick(float delta_time)
	{
		m_Tick += delta_time;
		if (m_Tick >= TICK_INTERVAL_SEC) CheckInSafezone();
	}
	
	void CheckInSafezone()
	{
		ref NF_Bases_Safezone safezone = GetNFBasesManager().CheckPlayerInSafezone(m_Player);
		if (safezone) {
			if (safezone.GetTeam() != m_Player.GetNFTeam()) {
				m_ShowAlert = true;
				m_RestrictedAreaTick += m_Tick;
				m_Player.SetAllowDamage(true);
			} else {
				m_ShowAlert = false;
				m_RestrictedAreaTick = 0;
			}
		} else {
			m_ShowAlert = false;
			m_RestrictedAreaTick = 0;
		}
		
		if (m_RestrictedAreaTick >= RESTRICTED_AREA_SEC) {
			m_Player.SetHealth( "GlobalHealth", "Health", 0 );
		}
		
		bool isInSafezone = !!safezone;
		int alertTime = (int)(RESTRICTED_AREA_SEC - m_RestrictedAreaTick);
		if (isInSafezone != m_IsInSafezone) {
			m_Player.SetAllowDamage(!isInSafezone);
		}
		
		if (isInSafezone != m_IsInSafezone || alertTime != m_AlertTime) {
			m_IsInSafezone = isInSafezone;
			m_AlertTime = alertTime;
			
			m_Player.SetIsInSafezone(isInSafezone);
			UpdateGUI();
		}
		
		m_Tick = 0;
	}
	
	void UpdateGUI()
	{
		GetRPCManager().SendRPC("NF_Bases", "RPCUpdateSafezoneState", new Param3< bool, bool, int >( m_IsInSafezone, m_ShowAlert, m_AlertTime ), true, m_Player.GetIdentity());
	}
}
