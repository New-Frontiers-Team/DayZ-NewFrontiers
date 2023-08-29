class NF_QuestListItem
{
    private bool m_Selected;
    private ref NF_Quest m_Quest;
	
    private ref Widget m_LayoutRoot;
	private ref ButtonWidget m_Button;
	private ref TextWidget m_Text;

    void NF_QuestListItem(Widget parent, ref NF_Quest quest)
    {
        m_Selected = false;
        m_Quest = quest;

        m_LayoutRoot = GetGame().GetWorkspace().CreateWidgets("NewFrontiersQuests/gui/layouts/questlistitem.layout", parent);
		
		m_Button = ButtonWidget.Cast(m_LayoutRoot.FindAnyWidget("Button"));
        m_Text = TextWidget.Cast(m_LayoutRoot.FindAnyWidget("TitleText"));
		
		m_Text.SetText(m_Quest.GetTitle());
    }
	
	ref NF_Quest GetQuest()
	{
		return m_Quest;
	}

    void SetSelected(bool selected)
    {
        m_Selected = selected;
		
		if (selected) {
			m_LayoutRoot.SetColor(ARGB(255, 200, 200, 200));
			m_Text.SetColor(ARGB(255, 12, 12, 12));
		} else {
			m_LayoutRoot.SetColor(ARGB(255, 10, 10, 10));
			m_Text.SetColor(ARGB(255, 255, 255, 255));
		}
    }
	
	ref ButtonWidget GetButton()
	{
		return m_Button;
	}
}