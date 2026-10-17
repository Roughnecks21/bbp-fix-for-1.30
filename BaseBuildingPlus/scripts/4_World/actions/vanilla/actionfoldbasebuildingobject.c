modded class ActionFoldBaseBuildingObjectCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 2 );
	}
}

modded class ActionFoldBaseBuildingObject
{
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTNonRuined( 10 );
		m_ConditionItem = new CCINotPresent;
	}
}