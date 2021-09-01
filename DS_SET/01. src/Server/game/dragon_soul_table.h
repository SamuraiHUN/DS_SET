search this:

	bool	GetDragonSoulExtValues(BYTE ds_type, BYTE grade_idx, OUT float& prob, OUT DWORD& by_product);

add below this:

#ifdef __DS_SET__
	uint8_t	GetBasicApplyCount(uint8_t iType);
	bool	GetBasicApplyValue(uint8_t iType, uint16_t iApplyType, int& iApplyValue);
	bool	GetAdditionalApplyValue(uint8_t iType, uint16_t iApplyType, int& iApplyValue);
#endif