modded class MissionServer
{
    void MissionServer()
    {
        BBPConfig obfv_bbpSettings = BBPGlobals.Get();
        GetDayZGame().setBBPGlobals(obfv_bbpSettings);
        GetRPCManager().AddRPC( "BaseBuildingPlus", "BBP_SYNC_SIZES", this, SingleplayerExecutionType.Both );
    }

    void BBP_SYNC_SIZES(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (!GetGame().IsServer() || !sender) return;
        Param2<PlayerBase, int> obfv_data;
        if (!ctx.Read(obfv_data)) return;
        PlayerBase obfv_player = obfv_data.param1;
        if (!obfv_player || !obfv_player.GetIdentity() || obfv_player.GetIdentity().GetId() != sender.GetId()) return;
        if (obfv_data.param2 < 1 || obfv_data.param2 > 2) return;
        obfv_player.BBPsetSize(obfv_data.param2);
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
		PlaceCementMixers();
		
		#ifdef GAMELABS
        GetGameLabs().AddMonitoredAction("ActionDismantleBBP");
        GetGameLabs().AddMonitoredAction("ActionDestroyBBP");
		#endif 
    }
    
    void PlaceCementMixers()
    {
        BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
        if (!bbp_config) return;
        array<ref CementMixerLocations> CementMixerLoc = bbp_config.BBP_CementMixerLocations;
        if (CementMixerLoc)
        {
            CementMixerLocations CM;
            for ( int i = 0; i < CementMixerLoc.Count(); i++ )
            {
                if (CementMixerLoc.Get(i))
                {
                    CM = CementMixerLoc.Get(i);
                    vector position = CM.position;
                    vector orientation = CM.orientation;
                    Object a = GetGame().CreateObject("BBP_Cement_Mixer_Static", position, false);
                    if (a)
                    {
                        a.SetPosition(position);
                        a.SetOrientation(orientation);
                    }        
                }
            }
        }
    }
}
