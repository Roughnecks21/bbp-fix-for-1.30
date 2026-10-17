/*class WB_Spawn_Item
{	
    void WB_Spawn_Item()
    {
		GetRPCManager().AddRPC( "BaseBuildingPlus", "BBP_Spawn_Kit_1", this, true);
		GetRPCManager().AddRPC( "BaseBuildingPlus", "BBP_Spawn_Kit_2", this, true);
		GetRPCManager().AddRPC( "BaseBuildingPlus", "BBP_Spawn_Kit_3", this, true);
    }

    void BBP_Spawn_Kit_1(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{	
		Param1< int > data;
        if ( !ctx.Read( data ) ) return;
		
		int BBP_Number = data.param1;
	
		BBP_Workbench Workbencher = BBP_Workbench.Cast( target );
		vector bbp_kit_position = "0 2.2 0";
		
		if (Workbencher && Workbencher.BBP_Spawn_Kit_1())
		{
			switch(BBP_Number)
			{
				case 0:
				GetGame().CreateObject("BBP_T1_WallKit", target.GetPosition() + bbp_kit_position, false  );
				break;
				
				case 3:
				GetGame().CreateObject("BBP_T1_Wall_HalfKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 6:
				GetGame().CreateObject("BBP_T1_DoorKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 9:
				GetGame().CreateObject("BBP_T1_RoofKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 12:
				GetGame().CreateObject("BBP_T1_FloorKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 15:
				GetGame().CreateObject("BBP_T1_WindowKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 18:
				GetGame().CreateObject("BBP_T1_StairKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 19:
				GetGame().CreateObject("BBP_T1_RampKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 20:
				GetGame().CreateObject("BBP_T1_Floor_HatchKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 21:
				GetGame().CreateObject("BBP_T1_GateKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 22:
				GetGame().CreateObject("BBP_T1_Ramp_WideKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 27:
				GetGame().CreateObject("BBP_T1_FoundationKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 30:
				GetGame().CreateObject("BBP_PillarKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 33:
				GetGame().CreateObject("BBP_T1_Roof_HatchKit", target.GetPosition() + bbp_kit_position, false );
				break;
			}
		}
	}
	
	void BBP_Spawn_Kit_2(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{	
		Param1< int > data;
        if ( !ctx.Read( data ) ) return;
		
		int BBP_Number = data.param1;
	
		BBP_Workbench Workbencher = BBP_Workbench.Cast( target );
		vector bbp_kit_position = "0 2.2 0";
		
		if (Workbencher && Workbencher.BBP_Spawn_Kit_2())
		{
			switch(BBP_Number)
			{
				case 1:
				GetGame().CreateObject("BBP_T2_WallKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 4:
				GetGame().CreateObject("BBP_T2_Wall_HalfKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 7:
				GetGame().CreateObject("BBP_T2_DoorKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 10:
				GetGame().CreateObject("BBP_T2_RoofKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 13:
				GetGame().CreateObject("BBP_T2_FloorKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 16:
				GetGame().CreateObject("BBP_T2_WindowKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 25:
				GetGame().CreateObject("BBP_T2_GateKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 28:
				GetGame().CreateObject("BBP_T2_FoundationKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 34:
				GetGame().CreateObject("BBP_T2_Roof_HatchKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 35:
				GetGame().CreateObject("BBP_T2_StairKit", target.GetPosition() + bbp_kit_position, false );
				break;
			}
		}
	}
	
	void BBP_Spawn_Kit_3(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{	
		Param1< int > data;
        if ( !ctx.Read( data ) ) return;
		
		int BBP_Number = data.param1;
	
		BBP_Workbench Workbencher = BBP_Workbench.Cast( target );
		vector bbp_kit_position = "0 2.2 0";
		
		if (Workbencher && Workbencher.BBP_Spawn_Kit_3())
		{
			switch(BBP_Number)
			{	
				case 2:
				GetGame().CreateObject("BBP_T3_WallKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 5:
				GetGame().CreateObject("BBP_T3_Wall_HalfKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 8:
				GetGame().CreateObject("BBP_T3_DoorKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 11:
				GetGame().CreateObject("BBP_T3_RoofKit", target.GetPosition() + bbp_kit_position, false );	
				break;
				
				case 14:
				GetGame().CreateObject("BBP_T3_FloorKit", target.GetPosition() + bbp_kit_position, false );
				break;

				case 17:
				GetGame().CreateObject("BBP_T3_WindowKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 24:
				GetGame().CreateObject("BBP_T3_Floor_HatchKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 26:
				GetGame().CreateObject("BBP_T3_GateKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 29:
				GetGame().CreateObject("BBP_T3_FoundationKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 31:
				GetGame().CreateObject("BBP_T3_StairKit", target.GetPosition() + bbp_kit_position, false );
				break;
				
				case 32:
				GetGame().CreateObject("BBP_T3_Roof_HatchKit", target.GetPosition() + bbp_kit_position, false );
				break;
			}
		}
	}
};

modded class MissionServer
{
    ref WB_Spawn_Item m_WB_Spawn_Item;

    void MissionServer()
    {
        m_WB_Spawn_Item = new ref WB_Spawn_Item();
    }
};
*/