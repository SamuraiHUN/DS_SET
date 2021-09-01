search this:

void CItemManager::Destroy()

add above this:

#ifdef ENABLE_DS_SET
bool CItemManager::LoadDragonSoulTable(const char* szDragonSoulTable)
{
	if (!m_DragonSoulTable)
	{
		TraceError("DragonSoulTable not initialized!");
		return false;
	}

	return m_DragonSoulTable->Load(szDragonSoulTable);
}

CDragonSoulTable* CItemManager::GetDragonSoulTable()
{
	return m_DragonSoulTable;
}
#endif

search this:

CItemManager::CItemManager() : m_pSelectedItemData(NULL)

overwrite with:

CItemManager::CItemManager() : m_pSelectedItemData(NULL)
{
#ifdef ENABLE_DS_SET
	m_DragonSoulTable = new CDragonSoulTable;
#endif
}