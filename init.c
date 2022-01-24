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

		string JacketArray[] = { "HuntingJacket_Brown", "HuntingJacket_Autumn", "HuntingJacket_Spring", "HuntingJacket_Summer" };
		itemEnt = player.GetInventory().CreateInInventory( JacketArray[1] );

		string PantsArray[] = { "HunterPants_Brown", "HunterPants_Autumn", "HunterPants_Spring", "HunterPants_Summer" };
		itemEnt = player.GetInventory().CreateInInventory( PantsArray[1] );

		string FaceCoverArray[] = { "BalaclavaMask_Beige", "BalaclavaMask_Black", "BalaclavaMask_Blackskull", "BalaclavaMask_Green" };
		itemEnt = player.GetInventory().CreateInInventory( FaceCoverArray[1] );

		string BootsArray[] = { "MilitaryBoots_Beige", "MilitaryBoots_Brown", "MilitaryBoots_Black", "MilitaryBoots_Bluerock" };
		itemEnt = player.GetInventory().CreateInInventory( BootsArray[1] );

		string GlovesArray[] = { "WorkingGloves_Beige", "WorkingGloves_Black", "WorkingGloves_Brown", "WorkingGloves_Yellow" };
		itemEnt = player.GetInventory().CreateInInventory( GlovesArray[1] );

		string HatArray[] = { "Ushanka_Black", "Ushanka_Green", "Ushanka_Black", "Ushanka_Blue" };
		itemEnt = player.GetInventory().CreateInInventory( HatArray[1] );

		string VestArray[] = { "HuntingVest", "HuntingVest", "HuntingVest", "HuntingVest" };
		itemEnt = player.GetInventory().CreateInInventory( VestArray[1] );

		string BagArray[] = { "HuntingBag", "HuntingBag", "HuntingBag", "HuntingBag" };
		itemEnt = player.GetInventory().CreateInInventory( BagArray[1] );

		string BeltArray[] = { "LeatherBelt_Beige", "LeatherBelt_Black", "LeatherBelt_Brown", "LeatherBelt_Natural" };
		itemEnt = player.GetInventory().CreateInInventory( BeltArray[1] );



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
		if ( itemClothing )

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
		itemEnt = player.GetInventory().CreateInInventory("Canteen");
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

		itemEnt = player.GetInventory().CreateInInventory("MP5K");
		itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
		itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
		itemEnt = player.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
		itemEnt = player.GetInventory().CreateInInventory("PistolSuppressor");
		itemEnt = player.GetInventory().CreateInInventory("MP5k_StockBttstck");
		itemEnt = player.GetInventory().CreateInInventory("MP5_RailHndgrd");
		itemEnt = player.GetInventory().CreateInInventory("ACOGOptic");



	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
