modded class MiscGameplayFunctions
{
	// 1.30 variant-index overload: keep BBP's permissive building behavior.
	override static bool ComplexBuildCollideCheckClient(PlayerBase player, ActionTarget target, ItemBase item, int constraction_index)
	{
		if (!player || !target) return false;
		Object obfv_target = target.GetObject();
		if (obfv_target && obfv_target.IsInherited(BBP_BASE))
		{
			BaseBuildingBase obfv_base = BaseBuildingBase.Cast(obfv_target);
			if (obfv_base && obfv_base.GetConstruction() && !player.IsLeaning()) return true;
			return false;
		}
		return super.ComplexBuildCollideCheckClient(player, target, item, constraction_index);
	}
}
