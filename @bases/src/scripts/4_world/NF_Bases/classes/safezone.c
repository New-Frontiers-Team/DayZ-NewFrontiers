class NF_Bases_Safezone
{
    private int m_faction;
    private vector m_position;
	private int m_radius;
    private int m_minReputation;

    void NF_Bases_Safezone(NF_Bases_SafezoneData data, int faction)
    {
        m_faction = faction;
        m_position = data.position.ToVector();
        m_radius = data.radius;
        m_minReputation = data.min_reputation;
    }

    int GetFaction()
    {
        return m_faction;
    }

    vector GetPosition()
    {
        return m_position;
    }

    int GetRadius()
    {
        return m_radius;
    }

    int GetMinReputation()
    {
        return m_minReputation;
    }

    bool IsInside(vector targetPosition)
    {
        float distance = NF_Vector.Distance2D(m_position, targetPosition);
        return distance <= m_radius;
    }

    bool IsAllowed(NF_Player player)
    {
        int reputation = player.GetReputation(m_faction);
        return reputation >= m_minReputation;
    }
}
