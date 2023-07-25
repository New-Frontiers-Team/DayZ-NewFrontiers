modded class Weapon_Base
{  
    override void OnFire(int muzzle_index)
    {
        super.OnFire(muzzle_index);
		
        PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
        if (player) {
            player.NF_SetCombatMode();
        }
    }
}