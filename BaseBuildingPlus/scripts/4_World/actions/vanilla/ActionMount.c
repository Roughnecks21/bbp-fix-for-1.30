// From 1.26 m_SlotName in Mount and UnMount BarbedWire is DEPRECATED in vanilla. Must be add new m_SlotNameValue variable.
// Fixed the issue with incorrect slot health assignment.

modded class ActionMountBarbedWire
{
	string m_SlotNameValue;

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();

		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);

			BarbedWire barbed_wire = BarbedWire.Cast(bbpbase.FindAttachmentBySlotName("Wall_BarbedWire_1"));
			BarbedWire barbed_wire2 = BarbedWire.Cast(bbpbase.FindAttachmentBySlotName("Wall_BarbedWire_2"));

			if (bbpbase)
			{
				if (barbed_wire && !barbed_wire.IsMounted())
				{
					m_SlotNameValue = "Wall_BarbedWire_1";
					return true;
				}
				if (barbed_wire2 && !barbed_wire2.IsMounted())
				{
					m_SlotNameValue = "Wall_BarbedWire_2";
					return true;
				}
			}
		}

		return super.ActionCondition(player, target, item);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_Target.GetObject().IsInherited(BBP_BASE))
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast(action_data.m_Target.GetObject());
			// mount and refresh parent
			BarbedWire wire = BarbedWire.Cast(base_building.FindAttachmentBySlotName(m_SlotNameValue));
			wire.SetMountedState(true);
		}
		else
			super.OnFinishProgressServer(action_data);
	}
}