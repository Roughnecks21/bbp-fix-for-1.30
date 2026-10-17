class BBP_Admin_Hammer extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionMineTree);
		AddAction(ActionMineBush);
		AddAction(ActionBuildPart);
		AddAction(ActionDismantlePart);
		AddAction(ActionDestroyPart);
		AddAction(ActionSawPlanks);
		AddAction(ActionUnrestrainTarget);
	}
	
	override bool isBBPAdminTool()
	{
		return true;
	}
}