modded class NF_Player : RestCallback
{
    private ref NF_Squad m_Squad;

    NF_Squad GetSquad()
    {
        if (!m_Squad) return null;

        return m_Squad;
    }

    void JoinSquad(ref NF_Squad squad)
    {
        m_Squad = squad;
    }

    void LeaveSquad(ref NF_Squad squad)
    {
        m_Squad = null;
    }
}