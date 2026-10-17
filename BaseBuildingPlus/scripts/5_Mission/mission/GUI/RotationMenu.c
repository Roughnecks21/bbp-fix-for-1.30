class RotationMenu extends UIScriptedMenu
{
	protected Widget w_Root;
	
    ImageWidget		img_background;
	ButtonWidget	roll_rot;
	ButtonWidget	pitch_rot;
	ButtonWidget	yaw_rot;
	ButtonWidget	reset_rot;
	ButtonWidget	en_adv_rot;
	ButtonWidget	dis_adv_rot;
	ButtonWidget	en_freeze;
	ButtonWidget	dis_freeze;
	ButtonWidget	bbp_for_back;
	ButtonWidget	bbp_up_down;
	ButtonWidget	bbp_left_right;
	ButtonWidget	bbp_imdisabled;

	void RotationMenu()
	{		
	}	
	
	void ~RotationMenu()
	{
	}
	
	int getBBP_AdvancedRotation()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_AdvancedRotation;
		}
		else
		{
			return 0;
		}
	}
	
	
    override Widget Init()
    {
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "BaseBuildingPlus/GUI/layouts/RotationMenu.layout" );
		//w_Root.Show( false );

		roll_rot 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "roll_rot" ) );
		pitch_rot 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "pitch_rot" ) );
		yaw_rot 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "yaw_rot" ) );
		en_adv_rot		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "en_adv_rot" ) );
		dis_adv_rot		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "dis_adv_rot" ) );
		reset_rot 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "reset_rot" ) );
		en_freeze		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "en_freeze" ) );
		dis_freeze 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "dis_freeze" ) );
		bbp_for_back 	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "holo_for_back" ) );
		bbp_up_down 	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "holo_up_down" ) );
		bbp_left_right 	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "holo_left_right" ) );
		bbp_imdisabled 	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "imdisabled" ) );

        img_background = ImageWidget.Cast( layoutRoot.FindAnyWidget( "I_Track0" ) );

        return layoutRoot;
    }
	
	override void Update( float timeslice )
	{
		super.Update( timeslice );
		
		if(!getBBP_AdvancedRotation())
		{
			bbp_imdisabled.Show(true);
		}
		
		if(getBBP_AdvancedRotation())
		{
			bbp_imdisabled.Show(false);
			
			if(!BBP_Rotate)
			{
				roll_rot.Show(false);
				pitch_rot.Show(false);
				yaw_rot.Show(false);
				dis_adv_rot.Show(false);
				en_adv_rot.Show(true);
				en_freeze.Show(false);
				dis_freeze.Show(false);
			}
			
			if(BBP_Rotate)
			{
				roll_rot.Show(true);
				pitch_rot.Show(true);
				yaw_rot.Show(true);
				dis_adv_rot.Show(true);
				en_adv_rot.Show(false);
			}
			
			bbp_for_back.Show(true);
			bbp_up_down.Show(true);
			bbp_left_right.Show(true);
			
			if(BBP_Rotate || (snappingEnabled_By_Looking && AUTO_BBP_SNAPPING_OBJECT != NULL))
			{
				if(BBP_Freeze)
				{
					en_freeze.Show(false);
					dis_freeze.Show(true);
				}
				if(!BBP_Freeze)
				{
					en_freeze.Show(true);
					dis_freeze.Show(false);
				}
			}
		}
	}

    override void OnShow()
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        g_Game.GetUIManager().ShowUICursor(true);
        g_Game.GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus( 1 );
        GetGame().GetMission().GetHud().Show( false );
    }

    override void OnHide()
    {
        g_Game.GetUIManager().ShowCursor(false);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetUIManager().Back();
        GetGame().GetMission().GetHud().Show( true );
    }
	
	override bool OnClick(Widget w, int x, int y, int button)
    {
		super.OnClick(w, x, y, button);
		
		if (button == MouseState.LEFT)
        {			
			if(w == en_adv_rot)
			{
				BBP_Rotate = true;
				return true;
			}
			else if(w == dis_adv_rot)
			{
				BBP_Rotate = false;
				BBP_Freeze = false;
				snappingEnabled_By_Looking = false;
				snappingEnabled = false;
				return true;
			}
			else if(w == en_freeze)
			{
				BBP_Freeze = true;
				return true;
			}
			else if(w == dis_freeze)
			{
				BBP_Freeze = false;
				return true;
			}
			else if(w == roll_rot)
			{
				pitch_rot_ 	= false;
				roll_rot_ 	= true;
				yaw_rot_ 	= false;
				return true;
			}
			else if(w == pitch_rot)
			{
				pitch_rot_ 	= true;
				roll_rot_ 	= false;
				yaw_rot_ 	= false;
				return true;
			}			
			else if(w == yaw_rot)
			{
				pitch_rot_ 	= false;
				roll_rot_ 	= false;
				yaw_rot_ 	= true;
				return true;
			}
			else if(w == reset_rot)
			{
				if(reset_rot_)
				{
					reset_rot_ = false;
				}
				
				else
				{
					reset_rot_ = true;
				}
				
				return true;
			}
			else if(w == bbp_for_back)
			{
				BBP_For_Back_ = true;
				BBP_Up_Down_  = false;
				BBP_Left_Right_ = false;
				return true;
			}
			else if(w == bbp_up_down)
			{
				BBP_For_Back_ = false;
				BBP_Up_Down_  = true;
				BBP_Left_Right_ = false;
				return true;
			}
			else if(w == bbp_left_right)
			{
				BBP_For_Back_ = false;
				BBP_Up_Down_  = false;
				BBP_Left_Right_ = true;
				return true;
			}
		}
		return false;
	}
}