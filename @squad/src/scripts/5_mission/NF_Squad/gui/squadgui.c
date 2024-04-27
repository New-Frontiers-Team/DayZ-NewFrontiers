class NF_Squad_InviteUI
{
    private Widget m_WidgetRoot;

    private Widget m_InviteWindow;

    private Widget m_HeaderBar;
    private TextWidget m_Inviter;
    private TextWidget m_Title;

    private Widget m_Body;
    private TextWidget m_Key1;
    private TextWidget m_Option1;
    private TextWidget m_Key2;
    private TextWidget m_Option2;

    void NF_Squad_InviteUI()
    {
        Init();
    }

    void Init()
    {
        m_WidgetRoot = GetGame().GetWorkspace().CreateWidgets("NewFrontiersSquad/gui/layouts/squadinvite_gui.layout");
    
        m_InviteWindow = m_WidgetRoot.FindAnyWidget("InviteWindow");
        m_InviteWindow.Show(false);

        m_HeaderBar = m_InviteWindow.FindAnyWidget("HeaderBar");
        m_Inviter = TextWidget.Cast(m_HeaderBar.FindAnyWidget("Inviter"));
        m_Title = TextWidget.Cast(m_HeaderBar.FindAnyWidget("Title"));
        m_Title.SetText("#nf_squad_invite_title");

        m_Body = m_InviteWindow.FindAnyWidget("Body");
        m_Key1 = TextWidget.Cast(m_Body.FindAnyWidget("Key1"));
        m_Option1 = TextWidget.Cast(m_Body.FindAnyWidget("Option1"));
        m_Key2 = TextWidget.Cast(m_Body.FindAnyWidget("Key2"));
        m_Option2 = TextWidget.Cast(m_Body.FindAnyWidget("Option2"));
    }

    void Invite(string playerName)
    {
        m_Inviter.SetText(playerName);
		
        m_InviteWindow.Show(true);
    }
}