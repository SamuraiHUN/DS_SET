search this:

	for (int i = DRAGON_SOUL_EQUIP_SLOT_START + DS_SLOT_MAX * deck_idx;
		i < DRAGON_SOUL_EQUIP_SLOT_START + DS_SLOT_MAX * (deck_idx + 1); i++)
	{
		LPITEM pItem = GetInventoryItem(i);
		if (NULL != pItem)
			DSManager::instance().ActivateDragonSoul(pItem);
	}


add below this:

#ifdef __DS_SET__
	DragonSoul_HandleSetBonus();
#endif


search this:

void CHARACTER::DragonSoul_DeactivateAll()

overwrite this function with:

void CHARACTER::DragonSoul_DeactivateAll()
{
	for (int i = DRAGON_SOUL_EQUIP_SLOT_START; i < DRAGON_SOUL_EQUIP_SLOT_END; i++)
	{
		DSManager::instance().DeactivateDragonSoul(GetInventoryItem(i), true);
	}

#ifdef __DS_SET__
	DragonSoul_HandleSetBonus();
#endif

	m_pointsInstant.iDragonSoulActiveDeck = -1;

	RemoveAffect(AFFECT_DRAGON_SOUL_DECK_0);
	RemoveAffect(AFFECT_DRAGON_SOUL_DECK_1);
#ifdef __DS_SET__
	RemoveAffect(NEW_AFFECT_DS_SET);
#endif
}

add below this function:

#ifdef __DS_SET__
void CHARACTER::DragonSoul_HandleSetBonus()
{
	bool bAdd = true;
	uint8_t iSetGrade;

	if (!DSManager::instance().GetDSSetGrade(this, iSetGrade))
	{
		CAffect* pkAffect = FindAffect(NEW_AFFECT_DS_SET);
		if (!pkAffect)
			return;

		iSetGrade = pkAffect->lApplyValue;
		bAdd = false;
	}
	else
	{
		AddAffect(NEW_AFFECT_DS_SET, APPLY_NONE, iSetGrade, 0, INFINITE_AFFECT_DURATION, 0, true);
	}

	const uint8_t iDeckIdx = DragonSoul_GetActiveDeck();
	const uint8_t iStartSlotIndex = WEAR_MAX_NUM + (iDeckIdx * DS_SLOT_MAX);
	const uint8_t iEndSlotIndex = iStartSlotIndex + DS_SLOT_MAX;

	for (uint8_t iSlotIndex = iStartSlotIndex; iSlotIndex < iEndSlotIndex; ++iSlotIndex)
	{
		const LPITEM pkItem = GetWear(iSlotIndex);
		if (!pkItem)
			return;

		for (uint8_t i = 0; i < ITEM_ATTRIBUTE_MAX_NUM; ++i)
		{
			if (pkItem->GetAttributeType(i))
			{
				const TPlayerItemAttribute& ia = pkItem->GetAttribute(i);
				int iSetValue = DSManager::instance().GetDSSetValue(i, ia.bType, pkItem->GetVnum(), iSetGrade);

				if (ia.bType == APPLY_SKILL)
				{
					iSetValue = bAdd ? iSetValue : iSetValue ^ 0x00800000;
				}
				else
				{
					iSetValue = bAdd ? iSetValue : -iSetValue;
				}

				ApplyPoint(ia.bType, iSetValue);
			}
		}
	}
}
#endif