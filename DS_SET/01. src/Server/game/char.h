search this:

	void	DragonSoul_CleanUp();

Add below this:

#ifdef __DS_SET__
	void DragonSoul_HandleSetBonus();
#endif