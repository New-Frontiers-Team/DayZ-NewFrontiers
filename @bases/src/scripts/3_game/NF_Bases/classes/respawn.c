class NF_Bases_RespawnData
{
    string position;
    int radius;
}

class NF_Bases_Respawn
{
    private vector m_position;
	private int m_radius;

    void NF_Bases_Respawn(NF_Bases_RespawnData data)
    {
        m_position = data.position.ToVector();
        m_radius = data.radius;
    }

    vector GetPosition()
    {
        return m_position;
    }

    int GetRadius()
    {
        return m_radius;
    }

	vector GetRandomPosition()
	{
		return NF_Vector.RandomPositionOnRadius(m_position, m_radius);
	}
}