class NF_KillFeedItem
{
    private ref NF_KillFeedWrapper m_Parent;

    private Widget m_WidgetRoot;
    private Widget m_Background;
    private TextWidget m_KillerName;
    private Widget m_KillerFaction;
    private TextWidget m_VictimName;
    private Widget m_VictimFaction;
    private ItemPreviewWidget m_KillerWeapon
    private TextWidget m_Distance;

    private EntityAI m_LocalWeapon;

    void NF_KillFeedItem(NF_KillFeedWrapper par, string kName, int kFaction, string vName, int vFaction, string wType, int dst)
    {
        m_Parent = par;

        Init();

        m_KillerName.SetText(FormatNick(kName));
        m_KillerFaction.SetColor(GetNFManager().GetFaction(kFaction).GetColor());
        m_VictimName.SetText(FormatNick(vName));
        m_VictimFaction.SetColor(GetNFManager().GetFaction(vFaction).GetColor());
        m_Distance.SetText(String(dst.ToString() + "m."));

        SetWeapon(wType);
    }

    void Init()
    {
        m_WidgetRoot = GetGame().GetWorkspace().CreateWidgets("NewFrontiersKillFeed/gui/layouts/murderinfo_gui.layout", m_Parent.GetRoot());
        m_KillerName = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("MurderName"));
        m_KillerFaction = m_WidgetRoot.FindAnyWidget("MurderFaction");
        m_VictimName = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("TargetName"));
        m_VictimFaction = m_WidgetRoot.FindAnyWidget("TargetFaction");
        m_KillerWeapon = ItemPreviewWidget.Cast(m_WidgetRoot.FindAnyWidget("MurderWeapon"));
        m_Distance = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("KillDst"));


        m_Background = m_WidgetRoot.FindAnyWidget("Background");

        float width, heigth;
        width = GetFeedWidth();
        m_Background.GetSize(null, heigth);
        m_Background.SetSize(width, heigth);

        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.Destroy, 10000, false);
    }

    string FormatNick(string source)
    {
        string result = source;
        if (result.Length() > 16) {
            result = result.Substring(0, 12) + "...";
        }
        return result;
    }

    void SetWeapon(string type)
    {
        EntityAI weapon = EntityAI.Cast(GetGame().CreateObject(type, vector.Zero, true));
        if (!weapon) {
            return;
        }
        m_KillerWeapon.SetItem(weapon);
        m_KillerWeapon.SetView(weapon.GetViewIndex());
        m_KillerWeapon.SetModelOrientation("0 0 0");
        m_LocalWeapon = weapon;
    }

    bool Destroy()
    {
        GetFeedWidth();
        m_Parent.RemoveItem(this);
        m_WidgetRoot.Unlink();
        if (m_LocalWeapon) {
            GetGame().ObjectDelete(m_LocalWeapon);
        }
        return true;
    }

    float GetFeedWidth()
    {
        float start, end, width;
        m_KillerName.GetPos(null, start);
        m_VictimName.GetPos(null, end);
        m_VictimName.GetSize(width, null);
        width = start + end + width;

        return width;
    }
}