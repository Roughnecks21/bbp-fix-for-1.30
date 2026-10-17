modded class PlayerBase
{
    protected int m_BBP_HOLO_SIZE = 1;

    override void Init()
    {
        super.Init();
        RegisterNetSyncVariableInt("m_BBP_HOLO_SIZE");
    }

    void BBPsetSize(int a)
    {
        if (a < 1 || a > 2) return;
        m_BBP_HOLO_SIZE = a;
        if (GetGame().IsServer()) SetSynchDirty();
    }

    int returnSize()
    {
        return m_BBP_HOLO_SIZE;
    }

	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
        AddAction(ActionTurnOffBBPMixer, InputActionMap);
		AddAction(ActionTurnOnBBPMixer, InputActionMap);
		AddAction(ActionFoldBBP, InputActionMap);
		//AddAction(ActionOpenBBPCraftUI, InputActionMap);
	}
	
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

        switch (rpc_type)
        {
            case BBPRPC.CHECKBBPCONFIG:
            {
                Param1<BBPConfig> configParams;
                if (!ctx.Read(configParams)) return;

                GetDayZGame().setBBPGlobals(configParams.param1);
                break;
            }
        }
    }
}

modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("BBP_Blueprint", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/book.anm");
    }
};
