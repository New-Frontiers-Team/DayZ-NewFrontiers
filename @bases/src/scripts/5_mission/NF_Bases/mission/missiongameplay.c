modded class MissionGameplay
{
	private ref NF_Bases_SafezoneUI m_NF_Bases_SafezoneUI;
	private bool m_NF_Bases_InSafezone;
	private bool m_NF_Bases_ShowAlert;
	private int m_NF_Bases_AlertTime;
	private bool m_NF_Bases_IsInCombatMode;
	private int m_NF_Bases_LeaveTime;

	void MissionGameplay()
	{
		m_NF_Bases_SafezoneUI = new NF_Bases_SafezoneUI();
		m_NF_Bases_InSafezone = false;
		m_NF_Bases_ShowAlert = false;
		m_NF_Bases_AlertTime = 0;
		m_NF_Bases_IsInCombatMode = false;
		m_NF_Bases_LeaveTime = 0;

		GetRPCManager().AddRPC("NF_Bases", "RPCUpdateSafezoneState", this, SingeplayerExecutionType.Both);
	}

	void RPCUpdateSafezoneState(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param5< bool, bool, int, bool, int> data;
		if (!ctx.Read(data)) return;

		bool inSafezone = data.param1;
		bool showAlert = data.param2;
		int alertTime = data.param3;
		bool isInCombatMode = data.param4;
		int leaveTime = data.param5;

		if (inSafezone != m_NF_Bases_InSafezone) {
			m_NF_Bases_InSafezone = inSafezone;
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "NF_Bases_UpdateInSafezone");
		}

		if (showAlert != m_NF_Bases_ShowAlert || isInCombatMode != m_NF_Bases_IsInCombatMode) {
			m_NF_Bases_ShowAlert = showAlert;
			m_NF_Bases_IsInCombatMode = isInCombatMode;
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "NF_Bases_UpdateShowAlert");
		}

		if (alertTime != m_NF_Bases_AlertTime) {
			m_NF_Bases_AlertTime = alertTime;
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "NF_Bases_UpdateAlertTime");
		}

		if (leaveTime != m_NF_Bases_LeaveTime) {
			m_NF_Bases_LeaveTime = leaveTime;
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "NF_Bases_UpdateLeaveTime");
		}
	}

	void NF_Bases_UpdateInSafezone()
	{
		if (!m_NF_Bases_SafezoneUI) return;
		
		m_NF_Bases_SafezoneUI.UpdateInSafezone(m_NF_Bases_InSafezone);
	}

	void NF_Bases_UpdateShowAlert()
	{
		if (!m_NF_Bases_SafezoneUI) return;

		m_NF_Bases_SafezoneUI.UpdateShowAlert(m_NF_Bases_ShowAlert, m_NF_Bases_IsInCombatMode);
	}

	void NF_Bases_UpdateAlertTime()
	{
		if (!m_NF_Bases_SafezoneUI) return;

		m_NF_Bases_SafezoneUI.UpdateAlertTime(m_NF_Bases_AlertTime);
	}

	void NF_Bases_UpdateLeaveTime()
	{
		if (!m_NF_Bases_SafezoneUI) return;

		m_NF_Bases_SafezoneUI.UpdateLeaveTime(m_NF_Bases_LeaveTime);
	}
}
