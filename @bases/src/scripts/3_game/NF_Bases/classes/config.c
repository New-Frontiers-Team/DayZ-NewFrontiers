class NF_Bases_Config
{
	static const string DIR_BASES = NF_DIR + "Bases/";

    private ref array<ref NF_Bases_Safezone> m_Safezones = new ref array< ref NF_Bases_Safezone >;
	private ref array<ref NF_Bases_Respawn> m_Respawns = new ref array< ref NF_Bases_Respawn >;

    void NF_Bases_Config()
    {
        Init();
    }

    void Init()
    {
        if (!FileExist(DIR_BASES))
			MakeDirectory(DIR_BASES);

        if (FileExist(DIR_BASES + "safezones.json")) {
            LoadSafezones();
        }
		
		if (FileExist(DIR_BASES + "respawns.json")) {
            LoadRespaws();
        }
    }

    void LoadSafezones()
    {
        JsonFileLoader<ref array<ref NF_Bases_Safezone>>.JsonLoadFile(DIR_BASES + "safezones.json", m_Safezones);
    }

	void LoadRespaws()
    {
        JsonFileLoader<ref array<ref NF_Bases_Respawn>>.JsonLoadFile(DIR_BASES + "respawns.json", m_Respawns);
    }
	
    array<ref NF_Bases_Safezone> GetSafezones()
    {
        return m_Safezones;
    }
	
	array<ref NF_Bases_Respawn> GetRespawns()
	{
		return m_Respawns;
	}
}