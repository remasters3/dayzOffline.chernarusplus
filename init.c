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
		string JacketArray[] = { "HikingJacket_Black", "HikingJacket_Blue", "HikingJacket_Green", "HikingJacket_Red" };
		itemEnt = player.GetInventory().CreateInInventory( JacketArray[JKIndex] );

		int PTIndex = Math.RandomInt( 0, 4 );
		string PantsArray[] = { "CargoPants_Beige", "CargoPants_Black", "CargoPants_Green", "CargoPants_Grey" };
		itemEnt = player.GetInventory().CreateInInventory( PantsArray[PTIndex] );

		int FCIndex = Math.RandomInt( 0, 4 );
		string FaceCoverArray[] = { "BalaclavaMask_Beige", "BalaclavaMask_Black", "BalaclavaMask_Blackskull", "BalaclavaMask_Green" };
		itemEnt = player.GetInventory().CreateInInventory( FaceCoverArray[FCIndex] );

		int BOIndex = Math.RandomInt( 0, 4 );
		string BootsArray[] = { "HikingBootsLow_Beige", "HikingBootsLow_Black", "HikingBootsLow_Blue", "HikingBootsLow_Grey" };
		itemEnt = player.GetInventory().CreateInInventory( BootsArray[BOIndex] );

		int GLVIndex = Math.RandomInt( 0, 4 );
		string GlovesArray[] = { "WorkingGloves_Beige", "WorkingGloves_Black", "WorkingGloves_Brown", "WorkingGloves_Yellow" };
		itemEnt = player.GetInventory().CreateInInventory( GlovesArray[GLVIndex] );

		int HATIndex = Math.RandomInt( 0, 4 );
		string HatArray[] = { "RadarCap_Black", "RadarCap_Blue", "RadarCap_Brown", "RadarCap_Green" };
		itemEnt = player.GetInventory().CreateInInventory( HatArray[HATIndex] );

		int VSTIndex = Math.RandomInt( 0, 4 );
                string VestArray[] = { "PressVest_Blue", "PressVest_LightBlue", "PressVest_Blue", "PressVest_LightBlue" };
                itemEnt = player.GetInventory().CreateInInventory( VestArray[VSTIndex] );

		int BAGIndex = Math.RandomInt( 0, 4 );
		string BagArray[] = { "MountainBag_Blue", "MountainBag_Green", "MountainBag_Orange", "MountainBag_Red" };
                itemEnt = player.GetInventory().CreateInInventory( BagArray[BAGIndex] );

		int BLTIndex = Math.RandomInt( 0, 4 );
                string BeltArray[] = { "CivilianBelt", "CivilianBelt", "CivilianBelt", "CivilianBelt" };
                itemEnt = player.GetInventory().CreateInInventory( BeltArray[BLTIndex] );

		int ABIndex = Math.RandomInt( 0, 7 );
                string ArmbandArray[] = { "Armband_Black", "Armband_Green", "Armband_Orange", "Armband_Blue", "Armband_Red", "Armband_White","Armband_Yellow" };
                itemEnt = player.GetInventory().CreateInInventory( ArmbandArray[ABIndex] );

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{


			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 2 );

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
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
		//if ( itemClothing )

		itemClothing = player.FindAttachmentBySlotName( "Feet" );

		itemEnt = player.GetInventory().CreateInInventory("Compass");
		itemEnt = player.GetInventory().CreateInInventory("ChernarusMap");
		itemEnt = player.GetInventory().CreateInInventory("Headtorch_Black");

		itemEnt = player.GetInventory().CreateInInventory("CombatKnife");
		itemEnt = player.GetInventory().CreateInInventory("Matchbox");
		itemEnt = player.GetInventory().CreateInInventory("Battery9V");
		itemEnt = player.GetInventory().CreateInInventory("Battery9V");
		itemEnt = player.GetInventory().CreateInInventory("DuctTape");
		itemEnt = player.GetInventory().CreateInInventory("Whetstone");
		itemEnt = player.GetInventory().CreateInInventory("CanOpener");
		itemEnt = player.GetInventory().CreateInInventory("WoodAxe");
		itemEnt = player.GetInventory().CreateInInventory("SewingKit");
		itemEnt = player.GetInventory().CreateInInventory("WeaponCleaningKit");

		itemEnt = player.GetInventory().CreateInInventory("BandageDressing");
		itemEnt = player.GetInventory().CreateInInventory("PurificationTablets");

		itemEnt = player.GetInventory().CreateInInventory("SardinesCan");
		itemEnt = player.GetInventory().CreateInInventory("BakedBeansCan");
		itemEnt = player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		itemEnt = player.GetInventory().CreateInInventory("SodaCan_Spite");
		itemEnt = player.GetInventory().CreateInInventory("TacticalBaconCan");
        
        // itemEnt = player.GetInventory().CreateInInventory("CanisterGasoline");
        // itemEnt = player.GetInventory().CreateInInventory("Pliers");
        // itemEnt = player.GetInventory().CreateInInventory("NailBox");
        // itemEnt = player.GetInventory().CreateInInventory("Canteen");
        // itemEnt = player.GetInventory().CreateInInventory("Canteen");
        // itemEnt = player.GetInventory().CreateInInventory("Canteen");
        // itemEnt = player.GetInventory().CreateInInventory("Canteen");
        // itemEnt = player.GetInventory().CreateInInventory("Canteen");
        // itemEnt = player.GetInventory().CreateInInventory("Canteen");
        

        array<string> MPFIVEArray = { "MP5K", "Mag_MP5_30Rnd", "Mag_MP5_30Rnd", "AmmoBox_9x19_25rnd", "AmmoBox_9x19_25rnd","AmmoBox_9x19_25rnd","PistolSuppressor","MP5k_StockBttstck","MP5_RailHndgrd","ACOGOptic" };
        array<string> UMPArray = { "UMP45", "Mag_UMP_25Rnd", "Mag_UMP_25Rnd", "AmmoBox_45ACP_25rnd", "AmmoBox_45ACP_25rnd","AmmoBox_45ACP_25rnd","PistolSuppressor","ACOGOptic" };
        array<string> CRSOArray = { "CZ61", "Mag_CZ61_20Rnd", "Mag_CZ61_20Rnd", "Mag_CZ61_20Rnd", "Mag_CZ61_20Rnd","Mag_CZ61_20Rnd","PistolSuppressor" };       
        array<string> FALArray = { "FAL", "Fal_OeBttstck", "Mag_FAL_20Rnd", "Mag_FAL_20Rnd", "Mag_FAL_20Rnd","Mag_FAL_20Rnd","ACOGOptic_6x"};
        array<string> SKSArray = { "SKS", "AmmoBox_762x39_20Rnd", "AmmoBox_762x39_20Rnd", "AmmoBox_762x39_20Rnd", "AmmoBox_762x39_20Rnd","PUScopeOptic" };
        array<string> MFOURArray = { "M4A1", "M4_MPHndgrd", "M4_OEBttstck", "Mag_CMAG_30Rnd", "Mag_CMAG_30Rnd", "Mag_CMAG_30Rnd","Mag_CMAG_30Rnd","ACOGOptic" };
        array<string> AKMArray = { "AKM", "AK_PlasticBttstck", "AK_PlasticHndgrd", "Mag_AKM_30Rnd", "Mag_AKM_30Rnd", "Mag_AKM_30Rnd","Mag_AKM_30Rnd","PSO11Optic" };
        array<string> FAMASArray = { "FAMAS", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd", "Mag_FAMAS_25Rnd","ACOGOptic" };
        array<string> VSSArray = { "VSS", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd", "Mag_VSS_10Rnd","PSO1Optic","Mag_VSS_10Rnd" };
        
        int gunz = Math.RandomInt( 0, 6 );
        // int gunz = 5;
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
