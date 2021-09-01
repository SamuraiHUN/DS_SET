search this:

bool DragonSoulTable::GetDragonSoulExtValues(BYTE ds_type, BYTE grade_idx, OUT float& prob, OUT DWORD& by_product)


add below this function:

#ifdef __DS_SET__
uint8_t DragonSoulTable::GetBasicApplyCount(uint8_t iType)
{
	TVecApplys vec_Applys;
	if (!GetBasicApplys(iType, vec_Applys))
	{
		return 0;
	}

	return vec_Applys.size();
}

bool DragonSoulTable::GetBasicApplyValue(uint8_t iType, uint16_t iApplyType, int& iApplyValue)
{
	TVecApplys vec_Applys;
	if (!GetBasicApplys(iType, vec_Applys))
	{
		return false;
	}

	for (const auto& it : vec_Applys)
	{
		if (it.apply_type == iApplyType)
		{
			iApplyValue = it.apply_value;
		}
	}

	return false;
}

bool DragonSoulTable::GetAdditionalApplyValue(uint8_t iType, uint16_t iApplyType, int& iApplyValue)
{
	TVecApplys vec_Applys;
	if (!GetAdditionalApplys(iType, vec_Applys))
	{
		return false;
	}

	for (const auto& it : vec_Applys)
	{
		if (it.apply_type == iApplyType)
		{
			iApplyValue = it.apply_value;
		}
	}

	return false;
}

#endif