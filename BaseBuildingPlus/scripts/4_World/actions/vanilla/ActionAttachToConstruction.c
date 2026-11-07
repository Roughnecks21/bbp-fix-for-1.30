modded class ActionAttachToConstruction
{
    // Keep DayZ's own action setup and inventory transfer; only choose the BBP slot.
    override protected int FindAndTranslateAttachmentSlot(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!player || !target || !item) return InventorySlots.INVALID;

        BBP_BASE bbp = BBP_BASE.Cast(target.GetObject());
        if (!bbp) return super.FindAndTranslateAttachmentSlot(player, target, item);

#ifdef EXPANSIONMODBASEBUILDING
        // BBP Expansion locks attach to the existing Combination Lock slot.
        if (item.IsKindOf("ExpansionCodeLock"))
        {
            if (!bbp.IsBBPGate() || !bbp.HasFullyConstructedGate() || bbp.IsOpened() || bbp.BBP_HasLock()) return InventorySlots.INVALID;

            int expansionSlot = InventorySlots.GetSlotIdFromString("Att_CombinationLock");
            if (expansionSlot != InventorySlots.INVALID && bbp.GetInventory().CanAddAttachmentEx(item, expansionSlot))
                return expansionSlot;

            return InventorySlots.INVALID;
        }
#endif

        if (item.IsKindOf("DigitalCodeLock"))
        {
            if (!bbp.IsBBPGate() || !bbp.HasFullyConstructedGate() || bbp.IsOpened() || bbp.BBP_HasLock()) return InventorySlots.INVALID;

            int slotId = InventorySlots.GetSlotIdFromString("Att_CodeLock");
            if (slotId != InventorySlots.INVALID && bbp.GetInventory().CanAddAttachmentEx(item, slotId))
                return slotId;

            return InventorySlots.INVALID;
        }

        // Preserve the old BBP combination-lock fallback.
        if (item.IsKindOf("CombinationLock"))
        {
            int originalSlot = super.FindAndTranslateAttachmentSlot(player, target, item);
            if (originalSlot != InventorySlots.INVALID) return originalSlot;

            InventoryLocation location = new InventoryLocation;
            if (bbp.GetInventory().FindFreeLocationFor(item, FindInventoryLocationType.ATTACHMENT, location))
                return location.GetSlot();

            return InventorySlots.INVALID;
        }

        return super.FindAndTranslateAttachmentSlot(player, target, item);
    }

#ifdef EXPANSIONMODBASEBUILDING
#ifndef SERVER
    // Expansion schedules its keypad for every Expansion_IsCodeLock(), including vanilla locks.
    // Redirect only BBP DigitalCodeLock attachments to the vanilla keypad.
    override void OnExecuteImpl(ActionData action_data)
    {
        super.OnExecuteImpl(action_data);

        if (!action_data || !action_data.m_Target || !action_data.m_MainItem) return;
        if (!DigitalCodeLock.Cast(action_data.m_MainItem)) return;
        if (!BBP_BASE.Cast(action_data.m_Target.GetParentOrObject())) return;

        ScriptCallQueue queue = GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY);
        queue.Remove(ExpansionCodeLockUI.Open);
        queue.CallLater(ExpansionCodeLockUI.Open, 250, false, action_data.m_MainItem, 0, "", false, true);
    }
#endif
#endif
}
