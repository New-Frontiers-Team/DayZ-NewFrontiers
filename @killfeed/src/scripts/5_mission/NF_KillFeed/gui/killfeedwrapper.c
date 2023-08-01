class NF_KillFeedWrapper
{
    private Widget m_WidgetRoot;
    private ref array<ref NF_KillFeedItem> m_Items;

    void NF_KillFeedWrapper()
    {
        Init();
    }

    void Init()
    {
        m_WidgetRoot = GetGame().GetWorkspace().CreateWidgets("NewFrontiersKillFeed/gui/layouts/feedwrapper_gui.layout", null);
        m_Items = new array<ref NF_KillFeedItem>();
    }

    Widget GetRoot()
    {
        return m_WidgetRoot;
    }

    void AddItem(Param3<string, string, string> data)
    {
        m_Items.Insert(new NF_KillFeedItem(this, data.param1, data.param2, data.param3));
    }

    void RemoveItem(NF_KillFeedItem item)
    {
        int idx = m_Items.Find(item);
        if (idx) {
            m_Items.Remove(idx);
        }
    }
}