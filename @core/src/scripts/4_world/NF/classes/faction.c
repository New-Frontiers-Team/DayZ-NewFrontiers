class NF_Faction
{
    private int m_Id;
    private string m_Name;
    private string m_Armband;
    private int m_Color;

    void NF_Faction(NF_FactionData data)
    {
        m_Id = data.id;
        m_Name = data.name;
        m_Armband = data.armband;
        m_Color = data.color.HexToInt();
    }

    int GetId()
    {
        return m_Id;
    }

    string GetName()
    {
        return m_Name;
    }

    string GetArmband()
    {
        return m_Armband;
    }

    int GetColor()
    {
        return m_Color;
    }
}