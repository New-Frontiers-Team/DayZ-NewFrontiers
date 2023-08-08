class NF_QuestsMenu: UIScriptedMenu
{
    private int m_QuestNPCId;
    private ref map<int, ref NF_QuestNPC> m_QuestNPCs;

    protected TextWidget m_TextTitle;
    protected ButtonWidget m_ButtonClose;

    void NF_QuestsMenu() {
        m_QuestNPCs = new map<int, ref NF_QuestNPC>;
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

    override bool OnClick( Widget w, int x, int y, int button )
    {
        super.OnClick(w, x, y, button);

        switch(w)
        {
            case m_ButtonClose:
                GetGame().GetUIManager().HideScriptedMenu(this);
                return true;
                break;
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

    void UpdateGUI()
    {
        ref NF_QuestNPC npc = m_QuestNPCs[m_QuestNPCId];
		if (!npc) return;

        m_TextTitle.SetText(npc.GetName());
    }
}
