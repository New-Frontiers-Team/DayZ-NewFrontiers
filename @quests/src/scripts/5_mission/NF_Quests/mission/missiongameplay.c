modded class MissionGameplay
{
    ref NF_QuestsMenu m_NF_QuestsMenu;

    void MissionGameplay()
    {
        GetRPCManager().AddRPC("NF_Quests", "NF_RPCGetQuestNPCData", this, SingeplayerExecutionType.Client);
    }

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

    override void NF_ShowQuestsMenu(int npcId)
    {
        UIScriptedMenu menu = GetUIManager().GetMenu();

        if (!menu) {
            if (!m_NF_QuestsMenu) {
                m_NF_QuestsMenu = new NF_QuestsMenu();
            }

            m_NF_QuestsMenu.SetQuestNPCId(npcId);
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

    void NF_RPCGetQuestNPCData(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param2<int, ref NF_QuestNPC> data;
        if (!ctx.Read(data)) return;

        int npcId = data.param1;
        if (!npcId) return;

        ref NF_QuestNPC npc = data.param2;
        if (!npc) return;

        m_NF_QuestsMenu.UpdateQuestNPC(npcId, npc);
    }
}
