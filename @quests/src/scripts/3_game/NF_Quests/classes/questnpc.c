class NF_QuestNPCData
{
    int id;
    string name;
	int faction;
    ref NF_QuestNPCCharacterData character;
    array<ref NF_QuestData> quests;
}

class NF_QuestNPCCharacterData
{
    string model;
    string position;
    string rotation;
    array<ref NF_QuestNPCItemData> inventory;
}

class NF_QuestNPCItemData
{
    string item;
    string slot;
    array<string> attachments;
}
