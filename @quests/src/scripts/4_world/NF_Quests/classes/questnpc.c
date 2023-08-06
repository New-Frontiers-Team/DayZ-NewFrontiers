class NF_QuestNPC
{
    private int m_Id;
    private string m_Name;
    private ref NF_Faction m_Faction;

    void NF_QuestNPC(NF_QuestNPCData data)
    {
        m_Id = data.id;
        m_Name = data.name;
        m_Faction = GetNFManager().GetFaction(data.faction);
        SpawnCharacter(data.character);
    }

    private void SpawnCharacter(NF_QuestNPCCharacterData data)
    {
        PlayerBase character = PlayerBase.Cast(GetGame().CreatePlayer(NULL, data.model, data.position.ToVector(), 0, "NONE"));
		character.SetOrientation(data.rotation.ToVector());
        character.NF_SetFaction(m_Faction);
        character.NF_SetIsQuestNPC(true);

        foreach (ref NF_QuestNPCItemData itemData: data.inventory) {
            EntityAI item;
            if (itemData.slot == "hands") {
                item = character.GetHumanInventory().CreateInHands(itemData.item);
            } else {
                item = character.GetInventory().CreateInInventory(itemData.item);
            }

            foreach(string attachment: itemData.attachments) {
                item.GetInventory().CreateAttachment(attachment);
            }
        }
    }
}