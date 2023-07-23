enum NF_Teams
{
    Independent,
    Blufor,
    Opfor,
}

class NF_Team
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
            case NF_Teams.Blufor:
                return "Blufor";
            case NF_Teams.Opfor:
                return "Opfor";
        }
		
		return "Independent";
    }
}
