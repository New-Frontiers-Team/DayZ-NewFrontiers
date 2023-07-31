class NF_Faction
{
    private int m_Id;
    private string m_Name;
    private string m_Armband;

    void NF_Faction(NF_FactionData data)
    {
        m_Id = data.id;
        m_Name = data.name;
        m_Armband = data.armband;
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
}