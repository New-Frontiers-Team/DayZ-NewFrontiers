modded class MissionGameplay
{
    private ref NF_QuestsMenu m_NF_QuestsMenu;

    void ~MissionGameplay()
    {
        NF_DestroyQuestsMenu();
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);

        Man player = GetGame().GetPlayer();
        if (player && player.IsUnconscious()) {
            NF_HideQuestsMenu();
        }

        UIScriptedMenu menu = m_UIManager.GetMenu();
        if (GetUApi().GetInputByID(UAUIBack).LocalPress() && menu && m_NF_QuestsMenu && menu == m_NF_QuestsMenu) {
            NF_HideQuestsMenu();
        }
    }

    NF_QuestsMenu NF_GetQuestsMenu()
    {
        return m_NF_QuestsMenu;
    }

    void NF_InitQuestsMenu()
    {
        if (!m_NF_QuestsMenu) {
            m_NF_QuestsMenu = new NF_QuestsMenu();
        }
    }

    override void NF_ShowQuestsMenu()
    {
        UIScriptedMenu menu = GetUIManager().GetMenu();

        if (!menu) {
            if (!m_NF_QuestsMenu) {
                NF_InitQuestsMenu();
            }

            GetUIManager().ShowScriptedMenu(m_NF_QuestsMenu, null);
        }
    }

    override void NF_HideQuestsMenu()
    {
        if (m_NF_QuestsMenu) {
            GetUIManager().HideScriptedMenu(m_NF_QuestsMenu);
        }
    }

    void NF_DestroyQuestsMenu()
    {
        if (m_NF_QuestsMenu) {
            m_NF_QuestsMenu.Close();
            m_NF_QuestsMenu = NULL;
        }
    }

    override void DestroyAllMenus()
    {
        super.DestroyAllMenus();

        NF_DestroyQuestsMenu();
    }

    override void ResetGUI()
    {
        super.ResetGUI();

        NF_DestroyQuestsMenu();
    }
}
