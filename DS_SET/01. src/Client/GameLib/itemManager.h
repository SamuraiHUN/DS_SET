search this:

#include "ItemData.h"

add below this:

#ifdef ENABLE_DS_SET
#include "DragonSoulTable.h"
#endif

search this:

		CItemData *		MakeItemData(DWORD dwIndex);


add below this:

#ifdef ENABLE_DS_SET
	public:
		bool LoadDragonSoulTable(const char* szDragonSoulTable);
		CDragonSoulTable* GetDragonSoulTable();

	protected:
		CDragonSoulTable* m_DragonSoulTable;
#endif