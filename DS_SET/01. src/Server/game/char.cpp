Search this:

	ComputeLeaderShipSkill();

add below this:

#ifdef __DS_SET__
	if (DragonSoul_IsDeckActivated())
		DragonSoul_HandleSetBonus();
#endif