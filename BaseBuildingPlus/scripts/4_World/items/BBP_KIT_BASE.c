class BBP_KIT_BASE extends ItemBase
{
	string NeededHologram()
    {
        return "Paper"; 
    }

	string BBPItem()
    {
        return "Paper"; 
    }

	override bool IsBasebuildingKit()
	{
		return true;
	}
	
	override bool isBBP_Object()
	{
		return true;
	}

	override bool IsDeployable()
	{
		return true;
	}
	
	bool GotThatCuttah()
	{
		return false;
	}
	
	bool TinyCuttah()
	{
		return false;
	}

	void BBP_PlayPlaceSound()
	{
		/* EffectSound sound =	SEffectManager.PlaySound( "woodenlog_drop_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true ); */
	}
	
	void ResetBBPSettings()
	{
		BBP_Rotate = false;
		BBP_Freeze = false;
		AUTO_BBP_SNAPPING_OBJECT = NULL;
		holoMove = 0.1;
		//holoOffset = "0 0 0";
		holoOffset = 0.0;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}	
}

/*class BBP_CLAIM_BASE extends ItemBase
{
	string NeededHologram()
    {
        return "WoodenPlank"; 
    }

	override bool IsBasebuildingKit()
	{
		return true;
	}
	
	void BBP_PlayPlaceSound()
	{
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	
	override bool IsDeployable()
	{
		return true;
	}
}*/

class BBP_FOUNDATION_KIT_BASE extends BBP_KIT_BASE {};

