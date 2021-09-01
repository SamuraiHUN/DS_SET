Search this:

	if (!pItem->IsEquipped() || !pItem->RemoveFromCharacter())

add above this:

#ifdef __DS_SET__
	if (ch->DragonSoul_IsDeckActivated())
	{
		ch->DragonSoul_HandleSetBonus();
		ch->RemoveAffect(NEW_AFFECT_DS_SET);
	}
#endif

search this:

void DSManager::RefreshDragonSoulState(LPCHARACTER ch)

add below the function this:

#ifdef __DS_SET__
bool DSManager::GetDSSetGrade(LPCHARACTER ch, uint8_t & iSetGrade)
{
	if (NULL == ch)
	{
		return false;
	}

	const uint8_t iDeckIdx = ch->DragonSoul_GetActiveDeck();
	const uint16_t wDragonSoulDeckAffectType = AFFECT_DRAGON_SOUL_DECK_0 + iDeckIdx;
	if (!ch->FindAffect(wDragonSoulDeckAffectType))
	{
		return false;
	}

	const uint8_t iStartSlotIndex = WEAR_MAX_NUM + (iDeckIdx * DS_SLOT_MAX);
	const uint8_t iEndSlotIndex = iStartSlotIndex + DS_SLOT_MAX;

	iSetGrade = 0;

	for (uint8_t iSlotIndex = iStartSlotIndex; iSlotIndex < iEndSlotIndex; ++iSlotIndex)
	{
		const LPITEM pkItem = ch->GetWear(iSlotIndex);
		if (!pkItem)
		{
			return false;
		}

		if (!pkItem->IsDragonSoul())
		{
			return false;
		}

		if (!IsTimeLeftDragonSoul(pkItem))
		{
			return false;
		}

		if (!IsActiveDragonSoul(pkItem))
		{
			return false;
		}

		const uint8_t iGrade = GetGradeIdx(pkItem->GetVnum());
		if (iGrade < DRAGON_SOUL_GRADE_ANCIENT)
		{
			return false;
		}

		if (iSetGrade == 0)
		{
			iSetGrade = iGrade;
		}

		if (iSetGrade != iGrade)
		{
			return false;
		}
	}

	return true;
}

int DSManager::GetDSSetValue(uint8_t iAttributeIndex, uint16_t iApplyType, uint32_t iVnum, uint8_t iSetGrade)
{
	const uint8_t iType = GetType(iVnum);
	float fWeight;
	if (!m_pTable->GetWeight(iType, iSetGrade-1, 0, 0, fWeight))
	{
		return 0;
	}

	int iSetValue;
	if (iAttributeIndex < m_pTable->GetBasicApplyCount(iType))
	{
		m_pTable->GetBasicApplyValue(iType, iApplyType, iSetValue);
	}
	else
	{
		m_pTable->GetAdditionalApplyValue(iType, iApplyType, iSetValue);
	}

	if (iSetValue == 0)
	{
		return 0;
	}

	return (iSetValue * fWeight - 1) / 100 + 1;
}
#endif