modded class ActionNextCombinationLockDialOnTarget
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!player || !target) return false;

        BBP_BASE gate = BBP_BASE.Cast(target.GetObject());
        if (gate)
        {
            if (!gate.CanUseConstruction() || player.GetItemInHands()) return false;

            CombinationLock lock = gate.GetCombinationLock();
            if (!lock || !lock.IsLocked()) return false;

            ConstructionActionData actionData = player.GetConstructionActionData();
            if (!actionData) return false;

            actionData.SetCombinationLock(lock);
            return true;
        }

        return super.ActionCondition(player, target, item);
    }
}
