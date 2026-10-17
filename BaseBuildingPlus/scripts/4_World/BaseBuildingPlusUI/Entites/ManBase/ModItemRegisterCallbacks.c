/*
# ModItemRegisterCallbacks.c
#
# © 2021 BaseBuildingPlus Development Team
# BaseBuildingPlus Mod
# www.basebuildingplus.com
#
# All Rights Reserved.See License File For Further Information
# 
*/

modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("BBP_CRAFTINGBOOK_BASE", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/book.anm");
        pType.AddItemInHandsProfileIK("BBP_BuildPermit", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/paper.anm");
	};
};