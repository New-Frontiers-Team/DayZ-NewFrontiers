class NF_QuestData
{
    int id;
    string title;
    string description;
    array<ref NF_QuestObjectiveData> objectives;
    array<ref NF_QuestRewardData> rewards;
}

class NF_QuestObjectiveData
{
    string type;
    int ammount;
}

class NF_QuestRewardData
{
    string type;
    int ammount;
}
