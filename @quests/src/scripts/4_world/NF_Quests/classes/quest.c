class NF_Quest
{
    private int m_Id;
    private string m_Title;
    private string m_Description;
    private ref array<ref NF_QuestObjective> m_Objectives;
    private ref array<ref NF_QuestReward> m_Rewards;

    void NF_Quest(NF_QuestData data)
    {
        m_Id = data.id;
        m_Title = data.title;
        m_Description = data.description;
        m_Objectives = new ref array<ref NF_QuestObjective>;
        m_Rewards = new ref array<ref NF_QuestReward>;

        foreach (ref NF_QuestObjectiveData objective: data.objectives) {
            m_Objectives.Insert(new NF_QuestObjective(objective));
        }

        foreach (ref NF_QuestRewardData reward: data.rewards) {
            m_Rewards.Insert(new NF_QuestReward(reward));
        }
    }
	
	int GetId()
	{
		return m_Id;
	}

    string GetTitle()
    {
        return m_Title;
    }
	
	string GetDescription()
    {
        return m_Description;
    }
}

class NF_QuestObjective
{
    private string m_Type;
    private int m_Ammount;

    void NF_QuestObjective(NF_QuestObjectiveData data)
    {
        m_Type = data.type;
        m_Ammount = data.ammount;
    }
}

class NF_QuestReward
{
    private string m_Type;
    private int m_Ammount;

    void NF_QuestReward(NF_QuestRewardData data)
    {
        m_Type = data.type;
        m_Ammount = data.ammount;
    }
}
