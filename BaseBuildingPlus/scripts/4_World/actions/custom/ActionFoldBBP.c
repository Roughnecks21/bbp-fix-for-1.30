class ActionFoldBBPCB : ActionContinuousBaseCB
{
	PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 1.5 );
	}
}

class ActionFoldBBP: ActionContinuousBase
{
	void ActionFoldBBP()
	{
		m_CallbackClass = ActionFoldBBPCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINotPresent;
	}

	override string GetText()
	{
		return "#fold";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		BBP_Workbench bench;
		if (Class.CastTo(bench,target.GetObject()) && bench.IsEmpty())
		{
			return true;
		}
		
		return false;
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject.IsInherited(BBP_Workbench))
		{
			Object m_Object2;
			if (GetGame().IsServer())
			{
				m_Object2 = GetGame().CreateObjectEx( "BBP_Workbench_Kit", targetObject.GetPosition(), ECE_PLACE_ON_SURFACE );
				m_Object2.SetPosition(targetObject.GetPosition());
				GetGame().ObjectDelete(action_data.m_Target.GetObject());
			}
		}
	}
}
