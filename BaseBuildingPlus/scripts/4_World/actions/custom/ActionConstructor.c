modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
		
		actions.Insert(ActionTurnOnBBPMixer);
		actions.Insert(ActionTurnOffBBPMixer);
		actions.Insert(ActionFoldBBP);
		actions.Insert(ActionDismantleBBP);
		actions.Insert(ActionDestroyBBP);
		actions.Insert(ActionReadCraftingBook);		
		actions.Insert(ActionReadCraftingBookOnWB);
		actions.Insert(ActionGetBBPHP);
		actions.Insert(obfc_ActionBBPDigitalCodeLock);
		actions.Insert(ActionBBPTrustedOpen);			
		//actions.Insert(ActionOpenBBPCraftUI);
    }
}
