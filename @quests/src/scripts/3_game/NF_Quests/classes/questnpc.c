class NF_QuestNPCData
{
    int id;
    string name;
	int faction;
    ref NF_QuestNPCCharacterData character;
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
