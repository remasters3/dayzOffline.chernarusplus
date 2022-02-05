void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		player.RemoveAllItems();

		int JKIndex = Math.RandomInt( 0, 4 );
		string JacketArray[] = { "GorkaEJacket_Autumn", "GorkaEJacket_Flat", "GorkaEJacket_PautRev", "GorkaEJacket_Summer" };
		itemEnt = player.GetInventory().CreateInInventory( JacketArray[JKIndex] );

		int PTIndex = Math.RandomInt( 0, 4 );
		string PantsArray[] = { "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "GorkaPants_Summer" };
		itemEnt = player.GetInventory().CreateInInventory( PantsArray[PTIndex] );

		int FCIndex = Math.RandomInt( 0, 4 );
		string FaceCoverArray[] = { "BalaclavaMask_Beige", "BalaclavaMask_Black", "BalaclavaMask_Blackskull", "BalaclavaMask_Green" };
		itemEnt = player.GetInventory().CreateInInventory( FaceCoverArray[FCIndex] );

		int BOIndex = Math.RandomInt( 0, 4 );
		string BootsArray[] = { "JungleBoots_Beige", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive" };
		itemEnt = player.GetInventory().CreateInInventory( BootsArray[BOIndex] );

		int GLVIndex = Math.RandomInt( 0, 3 );
		string GlovesArray[] = { "TacticalGloves_Beige", "TacticalGloves_Green", "TacticalGloves_Black" };
		itemEnt = player.GetInventory().CreateInInventory( GlovesArray[GLVIndex] );

		int HATIndex = Math.RandomInt( 0, 4 );
		string HatArray[] = { "Mich2001Helmet", "Mich2001Helmet", "Mich2001Helmet", "Mich2001Helmet" };
		itemEnt = player.GetInventory().CreateInInventory( HatArray[HATIndex] );

		int VSTIndex = Math.RandomInt( 0, 4 );
                string VestArray[] = { "PlateCarrierVest", "PlateCarrierVest", "PlateCarrierVest", "PlateCarrierVest" };
                itemEnt = player.GetInventory().CreateInInventory( VestArray[VSTIndex] );

		int BLTIndex = Math.RandomInt( 0, 4 );
                string BeltArray[] = { "MilitaryBelt", "MilitaryBelt", "MilitaryBelt", "MilitaryBelt" };
                itemEnt = player.GetInventory().CreateInInventory( BeltArray[BLTIndex] );


		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{


			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 2 );

			string chemlightArray[] = { "M18SmokeGrenade_White", "M18SmokeGrenade_Green", "M18SmokeGrenade_Yellow", "M18SmokeGrenade_Red" };
			int rndIndex = Math.RandomInt( 0, 4 );
			itemEnt = itemClothing.GetInventory().CreateInInventory( chemlightArray[rndIndex] );


			rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory( "Apple" );
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory( "Pear" );
			else
				itemEnt = player.GetInventory().CreateInInventory( "Plum" );

			SetRandomHealth( itemEnt );
		}

		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		itemClothing = player.FindAttachmentBySlotName( "Feet" );

		itemEnt = player.GetInventory().CreateInInventory("UniversalLight");
        
		itemEnt = player.GetInventory().CreateInInventory("Battery9V");
        itemEnt = player.GetInventory().CreateInInventory("Battery9V");
        itemEnt = player.GetInventory().CreateInInventory("Machete"); 
		
		itemEnt = player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
        itemEnt = player.GetInventory().CreateInInventory("BakedBeansCan_Opened");
		itemEnt = player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		itemEnt = player.GetInventory().CreateInInventory("SodaCan_Spite");

		itemEnt = player.GetInventory().CreateInInventory("M67Grenade");
        itemEnt = player.GetInventory().CreateInInventory("FlashGrenade");
        
        array<string> MPFIVEArray = { "MP5K", "Mag_MP5_30Rnd", "Mag_MP5_30Rnd", "AmmoBox_9x19_25rnd", "AmmoBox_9x19_25rnd","AmmoBox_9x19_25rnd","PistolSuppressor","MP5k_StockBttstck","MP5_RailHndgrd","ACOGOptic" };
        array<string> UMPArray = { "UMP45", "Mag_UMP_25Rnd", "Mag_UMP_25Rnd", "AmmoBox_45ACP_25rnd", "AmmoBox_45ACP_25rnd","AmmoBox_45ACP_25rnd","PistolSuppressor","ACOGOptic" };
        array<string> CRSOArray = { "CZ61", "Mag_CZ61_20Rnd", "Mag_CZ61_20Rnd", "Mag_CZ61_20Rnd", "Mag_CZ61_20Rnd","Mag_CZ61_20Rnd","PistolSuppressor" };       
        array<string> FALArray = { "FAL", "Fal_OeBttstck", "Mag_FAL_20Rnd", "Mag_FAL_20Rnd", "Mag_FAL_20Rnd","Mag_FAL_20Rnd","ACOGOptic_6x"};
        array<string> SKSArray = { "SKS", "AmmoBox_762x39_20Rnd", "AmmoBox_762x39_20Rnd", "AmmoBox_762x39_20Rnd", "AmmoBox_762x39_20Rnd","PUScopeOptic" };
        array<string> MFOURArray = { "M4A1", "M4_MPHndgrd", "M4_OEBttstck", "Mag_CMAG_30Rnd", "Mag_CMAG_30Rnd", "Mag_CMAG_30Rnd","Mag_CMAG_30Rnd","ACOGOptic" };
        array<string> AKMArray = { "AKM", "AK_PlasticBttstck", "AK_PlasticHndgrd", "Mag_AKM_30Rnd", "Mag_AKM_30Rnd", "Mag_AKM_30Rnd","Mag_AKM_30Rnd","PSO11Optic" };
        array<string> FAMASArray = { "FAMAS", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd","ACOGOptic" };
        array<string> VSSArray = { "VSS", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd","PSO1Optic","Mag_VSS_10Rnd" };
        array<string> SCOUTArray = { "Scout", "Mag_Scout_5Rnd","Mag_Scout_5Rnd","Mag_Scout_5Rnd","Mag_Scout_5Rnd","Mag_Scout_5Rnd","Mag_Scout_5Rnd", "Mag_Scout_5Rnd", "Mag_Scout_5Rnd", "Mag_Scout_5Rnd", "Mag_Scout_5Rnd","Rangefinder","StarlightOptic" };
        array<string> MOSINArray = { "Mosin9130","Mosin_Compensator","PUScopeOptic","AmmoBox_762x54_20Rnd","AmmoBox_762x54_20Rnd","AmmoBox_762x54_20Rnd", "AmmoBox_762x54_20Rnd", "AmmoBox_762x54_20Rnd", "AmmoBox_762x54_20Rnd", "AmmoBox_762x54_20Rnd", };
        array<string> TUNDRAArray = { "Winchester70", "AmmoBox_308Win_20Rnd","AmmoBox_308Win_20Rnd","AmmoBox_308Win_20Rnd","AmmoBox_308Win_20Rnd","Rangefinder","HuntingOptic" };
        
        // int gunz = Math.RandomInt( 0, 9 );
        int gunz = 8;
        if ( gunz == 1 )
        {
            foreach(int i, string j: FALArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( FALArray[i] );
            }
        }
        else if ( gunz == 2 )
        {
            foreach(int k, string l: SKSArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( SKSArray[k] );
            }
        }
        else if ( gunz == 3 )
        {
            foreach(int m, string n: MFOURArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( MFOURArray[m] );
            }
        }
        else if ( gunz == 4 )
        {
            foreach(int o, string p: VSSArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( VSSArray[o] );
            }
        }
        else if ( gunz == 5 )
        {
            foreach(int q, string r: UMPArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( UMPArray[q] );
            }
        }
        else if ( gunz == 6 )
        {
            foreach(int s, string t: SCOUTArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( SCOUTArray[s] );
            }
        }
        else if ( gunz == 7 )
        {
            foreach(int u, string v: MOSINArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( MOSINArray[u] );
            }
        }
        else if ( gunz == 8 )
        {
            foreach(int w, string x: TUNDRAArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( TUNDRAArray[w] );
            }
        }
        else 
        {
            foreach(int a, string b: AKMArray)
            {
                itemEnt = player.GetInventory().CreateInInventory( AKMArray[a] );
            }        
        }

	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
