modded class ActionDeployObject
{
    override bool ActionConditionContinue( ActionData action_data )
	{
		if (action_data && action_data.m_MainItem && action_data.m_MainItem.IsKindOf("BBP_KIT_BASE")) return true;
		return super.ActionConditionContinue(action_data);
	}

    override void OnFinishProgressServer( ActionData action_data )
	{	
        if (!action_data || !action_data.m_MainItem || !action_data.m_MainItem.IsKindOf("BBP_KIT_BASE"))
        {
            super.OnFinishProgressServer(action_data);
            return;
        }
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		
		if ( !poActionData ) { return; }
		if( !action_data.m_MainItem || !action_data.m_Player || !action_data.m_Player.GetHologramServer() ) { return; }
		
		EntityAI entity_for_placing = action_data.m_MainItem;
		vector position = action_data.m_Player.GetLocalProjectionPosition();
		vector orientation = action_data.m_Player.GetLocalProjectionOrientation();
		
		action_data.m_Player.GetHologramServer().EvaluateCollision(action_data.m_MainItem);
		if (GetGame().IsMultiplayer() && action_data.m_Player.GetHologramServer().IsColliding()) return;
		
		action_data.m_Player.GetHologramServer().PlaceEntity( entity_for_placing );
		
		if ( GetGame().IsMultiplayer() )
			action_data.m_Player.GetHologramServer().CheckPowerSource();
		
		action_data.m_Player.PlacingCompleteServer();
		entity_for_placing.OnPlacementComplete( action_data.m_Player, position, orientation );		
		
		MoveEntityToFinalPosition( action_data, position, orientation );		
		GetGame().ClearJuncture( action_data.m_Player, entity_for_placing );
		action_data.m_MainItem.SetIsBeingPlaced( false );
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		poActionData.m_AlreadyPlaced = true;	
		action_data.m_MainItem.SoundSynchRemoteReset();
	}
    
    /*override void OnEndServer(ActionData action_data)
    {
        if ( action_data.m_MainItem.IsKindOf("BBP_BASE_KIT") )
        {
            PlaceObjectActionData poActionData;
            poActionData = PlaceObjectActionData.Cast(action_data);
            if (!poActionData.m_AlreadyPlaced)
            {
                EntityAI entity_for_placing = EntityAI.Cast(action_data.m_MainItem);
                GetGame().ClearJuncture(action_data.m_Player, entity_for_placing);
                action_data.m_MainItem.SetIsBeingPlaced(false);
            
                if (GetGame().IsMultiplayer())
                {
                    action_data.m_Player.PlacingCancelServer();
                    action_data.m_MainItem.SoundSynchRemoteReset();
                }
                else
                {
                    //local singleplayer
                    action_data.m_Player.PlacingCancelLocal();
                    action_data.m_Player.LocalTakeEntityToHands(entity_for_placing);
                }
            }
            else
            {
                GetGame().ObjectDelete(action_data.m_MainItem);
                action_data.m_MainItem.SetIsDeploySound(false);
                action_data.m_MainItem.SetIsPlaceSound(false);
                action_data.m_MainItem.SoundSynchRemoteReset();
            }
        }
        else
        {
            super.OnEndServer(action_data);
        }
    }*/
}
