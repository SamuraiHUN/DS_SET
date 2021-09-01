search this:

		DSManager::instance().ActivateDragonSoul(this);


add below this:

#ifdef __DS_SET__
		ch->DragonSoul_HandleSetBonus();
#endif