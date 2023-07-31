
class NF_Bases_Safezone
{
    private int m_faction;
    private vector m_position;
	private int m_radius;

    void NF_Bases_Safezone(NF_Bases_SafezoneData data, int faction)
    {
        m_faction = faction;
        m_position = data.position.ToVector();
        m_radius = data.radius;
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

    bool IsInside(vector targetPosition)
    {
        float distance = NF_Vector.Distance2D(m_position, targetPosition);
        return distance <= m_radius;
    }
}
