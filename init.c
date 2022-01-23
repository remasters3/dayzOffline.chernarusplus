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
                //int rndIndex = Math.RandomInt( 0, 4 );
                itemEnt = player.GetInventory().CreateInInventory( JacketArray[0] );
                itemEnt = player.GetInventory().CreateInInventory("HunterPants_Brown");
                itemEnt = player.GetInventory().CreateInInventory("HuntingVest");
                itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Beige");
                itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Brown");
                itemEnt = player.GetInventory().CreateInInventory("MilitaryBoots_Brown");
                itemEnt = player.GetInventory().CreateInInventory("Ushanka_Black");
                itemEnt = player.GetInventory().CreateInInventory("HuntingBag");
                itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");    // added items
                itemEnt = player.GetInventory().CreateInInventory("Compass");    // added items
                itemEnt = player.GetInventory().CreateInInventory("Canteen");    // added items
                itemEnt = player.GetInventory().CreateInInventory("SardinesCan");    // added items
                itemEnt = player.GetInventory().CreateInInventory("CombatKnife");    // added items
                itemEnt = player.GetInventory().CreateInInventory("CanOpener");    // added items
                itemEnt = player.GetInventory().CreateInInventory("ChernarusMap");    // added items
                itemEnt = player.GetInventory().CreateInInventory("MP5K");    // added items
                itemEnt = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");    // added items
                itemEnt = player.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");    // added items
                itemEnt = player.GetInventory().CreateInInventory("BandageDressing");    // added items
                itemEnt = player.GetInventory().CreateInInventory("PurificationTablets");    // added items
                itemEnt = player.GetInventory().CreateInInventory("WoodAxe");    // added items
                itemEnt = player.GetInventory().CreateInInventory("BakedBeansCan");    // added items
                itemEnt = player.GetInventory().CreateInInventory("SodaCan_Pipsi");    // added items
                itemEnt = player.GetInventory().CreateInInventory("SodaCan_Spite");    // added items
                itemEnt = player.GetInventory().CreateInInventory("TacticalBaconCan");    // added items
                itemEnt = player.GetInventory().CreateInInventory("Matchbox");    // added items
                itemEnt = player.GetInventory().CreateInInventory("DuctTape");    // added items
                itemEnt = player.GetInventory().CreateInInventory("Whetstone");    // added items
                itemEnt = player.GetInventory().CreateInInventory("PistolSuppressor");    // added items
                itemEnt = player.GetInventory().CreateInInventory("MP5k_StockBttstck");    // added items
                itemEnt = player.GetInventory().CreateInInventory("Binoculars");    // added items
                itemEnt = player.GetInventory().CreateInInventory("SewingKit");    // added items
                itemEnt = player.GetInventory().CreateInInventory("WeaponCleaningKit");    // added items

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 2 );

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt( 0, 4 );
			itemEnt = itemClothing.GetInventory().CreateInInventory( chemlightArray[rndIndex] );
			SetRandomHealth( itemEnt );

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
			SetRandomHealth( itemClothing );
		
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
