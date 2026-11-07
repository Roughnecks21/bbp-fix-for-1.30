modded class MissionServer
{
    void MissionServer()
    {
        BBPConfig bbpSettings = BBPGlobals.Get();
        GetDayZGame().setBBPGlobals(bbpSettings);
        GetRPCManager().AddRPC( "BaseBuildingPlus", "BBP_SYNC_SIZES", this, SingleplayerExecutionType.Both );
    }

    void BBP_SYNC_SIZES(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (!GetGame().IsServer() || !sender) return;
        Param2<PlayerBase, int> rpcData;
        if (!ctx.Read(rpcData)) return;
        PlayerBase requestPlayer = rpcData.param1;
        if (!requestPlayer || !requestPlayer.GetIdentity() || requestPlayer.GetIdentity().GetId() != sender.GetId()) return;
        if (rpcData.param2 < 1 || rpcData.param2 > 2) return;
        requestPlayer.BBPsetSize(rpcData.param2);
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);

        auto configParams = new Param1<BBPConfig>(GetDayZGame().getBBPGlobals());
        GetGame().RPCSingleParam(player, BBPRPC.CHECKBBPCONFIG, configParams, true, identity);
    }

    override void OnInit()
    {
        super.OnInit();
		
		#ifdef GAMELABS
        GetGameLabs().AddMonitoredAction("ActionDismantleBBP");
        GetGameLabs().AddMonitoredAction("ActionDestroyBBP");
		#endif 
    }
    
    // Wait for persisted world objects before placing configured static mixers.
    override void OnMissionStart()
    {
        super.OnMissionStart();
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlaceCementMixers, 20000, false);
    }

    void PlaceCementMixers()
    {
        if (!GetGame().IsServer()) return;
        BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
        if (!bbp_config || !bbp_config.BBP_CementMixerLocations) return;

        foreach (CementMixerLocations location : bbp_config.BBP_CementMixerLocations)
        {
            if (!location) continue;

            vector position = location.position;
            array<Object> objects = new array<Object>;
            array<CargoBase> cargos = new array<CargoBase>;
            GetGame().GetObjectsAtPosition3D(position, 1.5, objects, cargos);

            bool found = false;
            foreach (Object obj : objects)
            {
                if (obj && obj.IsKindOf("BBP_Cement_Mixer_Static") && vector.Distance(obj.GetPosition(), position) < 1.0)
                {
                    found = true;
                    break;
                }
            }
            if (found) continue;

            Object mixer = GetGame().CreateObject("BBP_Cement_Mixer_Static", position, false);
            if (mixer)
            {
                mixer.SetPosition(position);
                mixer.SetOrientation(location.orientation);
            }
        }
    }
}
