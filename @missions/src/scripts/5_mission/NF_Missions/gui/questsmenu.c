class NF_QuestsMenu: UIScriptedMenu
{
    protected ButtonWidget m_ButtonClose;

    void NF_QuestsMenu() { }

    void ~NF_QuestsMenu()
    {
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
    }

    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("NewFrontiersMissions/gui/layouts/questsmenu.layout");
        m_ButtonClose = ButtonWidget.Cast(layoutRoot.FindAnyWidget("CancelButton"));

        layoutRoot.Show(false);

        return layoutRoot;
    }

    override void OnShow()
    {
        super.OnShow();

        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
    }

    override void OnHide()
    {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);

        Close();
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
}
