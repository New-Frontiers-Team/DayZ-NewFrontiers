class NF_Bases_Respawn
{
	private int team;
    private string position;
   
	int GetTeam()
    {
        return team;
    }

    vector GetPosition()
    {
        return position.ToVector();
    }
}