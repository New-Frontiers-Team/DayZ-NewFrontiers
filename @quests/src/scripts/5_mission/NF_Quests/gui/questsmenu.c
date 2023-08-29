class NF_QuestsMenu: UIScriptedMenu
{
    private int m_QuestNPCId;
    private ref map<int, ref NF_QuestNPC> m_QuestNPCs;
    private ref array<ref NF_QuestListItem> m_QuestListItems;
	private int m_SelectedQuest;

    protected ref TextWidget m_TextTitle;
    protected ref WrapSpacerWidget m_QuestList;
    protected ref ButtonWidget m_ButtonClose;
	protected ref TextWidget m_QuestTitleText;
	protected ref MultilineTextWidget m_QuestDescriptionText;

    void NF_QuestsMenu() {
        m_QuestNPCs = new map<int, ref NF_QuestNPC>;
		m_QuestListItems = new array<ref NF_QuestListItem>;
    }

    void ~NF_QuestsMenu()
    {
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
    }

    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("NewFrontiersQuests/gui/layouts/questsmenu.layout");
        m_ButtonClose = ButtonWidget.Cast(layoutRoot.FindAnyWidget("CancelButton"));
        m_TextTitle = TextWidget.Cast(layoutRoot.FindAnyWidget("TitleText"));
        m_QuestList = WrapSpacerWidget.Cast(layoutRoot.FindAnyWidget("QuestList"));
		m_QuestTitleText = TextWidget.Cast(layoutRoot.FindAnyWidget("QuestTitleText"));
		m_QuestDescriptionText = MultilineTextWidget.Cast(layoutRoot.FindAnyWidget("QuestDescriptionText"));

        layoutRoot.Show(false);

        return layoutRoot;
    }

    override void OnShow()
    {
        super.OnShow();

        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
    }

    override void OnHide()
    {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        super.OnClick(w, x, y, button);

        switch(w)
        {
            case m_ButtonClose:
                GetGame().GetUIManager().HideScriptedMenu(this);
                return true;
                break;
			default:
				foreach(ref NF_QuestListItem listItem: m_QuestListItems) {
					if (w == listItem.GetButton()) {
						int id = listItem.GetQuest().GetId();
						if (id != m_SelectedQuest) {
							SelectQuest(id);
						}
					}
		        }
        }

        return false;
    }

    void SetQuestNPCId(int npcId)
    {
        m_QuestNPCId = npcId;

        NF_QuestNPC npc;
		if (m_QuestNPCs.Contains(npcId)) {
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "UpdateGUI");
		} else {
            GetRPCManager().SendRPC("NF_Quests", "NF_RPCRequestQuestNPCData", new Param1<int>(npcId), true, NULL);
        }
    }

    void UpdateQuestNPC(int id, ref NF_QuestNPC npc)
    {
        m_QuestNPCs.Insert(id, npc);

        if (id == m_QuestNPCId) {
           	GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "UpdateGUI");
        }
    }

	private void SelectQuest(int questId)
	{
		m_SelectedQuest = questId;
		
		foreach(ref NF_QuestListItem listItem: m_QuestListItems) {
			if (listItem.GetQuest().GetId() == questId) {
				listItem.SetSelected(true);

				ref NF_Quest quest = listItem.GetQuest();
				m_QuestTitleText.SetText(quest.GetTitle());
				m_QuestDescriptionText.SetText(quest.GetDescription());
				m_QuestDescriptionText.Update();
			} else {
				listItem.SetSelected(false);
			}
		}
	}

    void UpdateGUI()
    {
        ref NF_QuestNPC npc = m_QuestNPCs[m_QuestNPCId];
		if (!npc) return;

        m_TextTitle.SetText(npc.GetName());
		m_QuestListItems.Clear();

		array<ref NF_Quest> quests = npc.GetQuests();
        foreach(ref NF_Quest quest: quests) {
            NF_QuestListItem questItem = new NF_QuestListItem(m_QuestList, quest);
            m_QuestListItems.Insert(questItem);
        }

		SelectQuest(m_QuestListItems.Get(0).GetQuest().GetId());
    }
}
