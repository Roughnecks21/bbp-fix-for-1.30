modded class MiscGameplayFunctions
{
	// 1.30 variant-index overload: keep BBP's permissive building behavior.
	override static bool ComplexBuildCollideCheckClient(PlayerBase player, ActionTarget target, ItemBase item, int constraction_index)
	{
		if (!player || !target) return false;
		Object targetObject = target.GetObject();
		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			BaseBuildingBase targetBase = BaseBuildingBase.Cast(targetObject);
			if (targetBase && targetBase.GetConstruction() && !player.IsLeaning()) return true;
			return false;
		}
		return super.ComplexBuildCollideCheckClient(player, target, item, constraction_index);
	}
}
