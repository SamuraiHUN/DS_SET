search this:

	char szSkillTableFileName[256];

add below this:

#ifdef ENABLE_DS_SET
	char szDragonSoulTable[256];
#endif

search this:

	snprintf(szSkillTableFileName, sizeof(szSkillTableFileName), "%s/SkillTable.txt", localePath);

add below this:

#ifdef ENABLE_DS_SET
	snprintf(szDragonSoulTable, sizeof(szDragonSoulTable), "%s/dragon_soul_table.txt", localePath);
#endif

search this:

	if (!rkItemMgr.LoadItemDesc(szItemDesc))
	{
		Tracenf("LoadLocaleData - LoadItemDesc(%s) Error", szItemDesc);
	}
	
add below this:

#ifdef ENABLE_DS_SET
	if (!rkItemMgr.LoadDragonSoulTable(szDragonSoulTable))
		Tracenf("LoadLocaleData - LoadDragonSoulTable(%s) Error", szDragonSoulTable);
#endif