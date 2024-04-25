class NF_Bases_SafezoneUI
{
	private Widget m_WidgetRoot;

	private Widget m_InSafezoneIcon;

	private Widget m_AlertWindow;
	private MultilineTextWidget m_ContentText;
	private TextWidget m_CounterText;

	private TextWidget m_LeaveCounter;

	void NF_Bases_SafezoneUI()
	{
		Init();
	}

	void Init()
	{
		m_WidgetRoot = GetGame().GetWorkspace().CreateWidgets("NewFrontiersBases/gui/layouts/safezone_gui.layout");

		m_InSafezoneIcon = m_WidgetRoot.FindAnyWidget("InSafezoneIcon");
		m_InSafezoneIcon.Show(false);

		m_AlertWindow = m_WidgetRoot.FindAnyWidget("AlertWindow");
		m_AlertWindow.Show(false);

		m_ContentText = MultilineTextWidget.Cast(m_AlertWindow.FindAnyWidget("ContentText"));

		m_CounterText = TextWidget.Cast(m_AlertWindow.FindAnyWidget("CounterText"));
		m_CounterText.SetText("0");

		m_LeaveCounter = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("LeaveCounter"));
		m_LeaveCounter.Show(false);
		m_LeaveCounter.SetText("0");
	}

	void UpdateInSafezone(bool inSafezone)
	{
		m_InSafezoneIcon.Show(inSafezone);
	}

	void UpdateShowAlert(bool showAlert, bool isInCombatMode)
	{
		m_AlertWindow.Show(showAlert);

		if (isInCombatMode) {
			m_ContentText.SetText("#nf_safezone_combatmode_alert");
		} else {
			m_ContentText.SetText("#nf_safezone_alert");
		}
	}

	void UpdateAlertTime(int seconds)
	{
		m_CounterText.SetText(seconds.ToString());
	}

	void UpdateLeaveTime(int seconds)
	{
		if (seconds != 0 && seconds != 15) {
			m_LeaveCounter.Show(true);
		} else {
			m_LeaveCounter.Show(false);
		}
		m_LeaveCounter.SetText(seconds.ToString());
	}
}
