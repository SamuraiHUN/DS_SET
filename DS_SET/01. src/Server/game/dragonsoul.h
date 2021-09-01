Search this:

	bool	HasActivateDragonSoul(const LPCHARACTER ch);

add below this:

#ifdef __DS_SET__
	bool GetDSSetGrade(LPCHARACTER ch, uint8_t & iSetGrade);
	int GetDSSetValue(uint8_t iAttributeIndex, uint16_t iApplyType, uint32_t iVnum, uint8_t iSetGrade);
#endif