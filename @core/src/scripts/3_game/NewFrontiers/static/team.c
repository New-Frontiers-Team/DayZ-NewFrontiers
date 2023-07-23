enum NewFrontiersTeams
{
    Independent,
    Blufor,
    Opfor,
}

class NewFrontiersTeam
{
    static const int NUM_OF_TEAMS = 3;

    static int GenerateTeam()
    {
        return Math.RandomInt(0, NUM_OF_TEAMS);
    }

    static string GetTeamName(int team)
    {
        switch (team)
        {
            case NewFrontiersTeams.Blufor:
                return "Blufor";
            case NewFrontiersTeams.Opfor:
                return "Opfor";
        }
		
		return "Independent";
    }
}
