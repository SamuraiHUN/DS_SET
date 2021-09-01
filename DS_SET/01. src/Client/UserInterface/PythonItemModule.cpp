Add include this:

#ifdef ENABLE_DS_SET
#include "../GameLib/DragonSoulTable.h"
#endif

before:

void initItem()


add this:

#ifdef ENABLE_DS_SET
PyObject* itemGetDSSetWeight(PyObject* poSelf, PyObject* poArgs)
{
	BYTE iSetGrade;
	if (!PyTuple_GetInteger(poArgs, 0, &iSetGrade))
		return Py_BadArgument();

	CDragonSoulTable* dsTable = CItemManager::Instance().GetDragonSoulTable();
	if (!dsTable)
		return Py_BuildException("DragonSoulTable not initalized");

	return Py_BuildValue("i", dsTable->GetDSSetWeight(iSetGrade));
}

PyObject* itemGetDSBasicApplyCount(PyObject* poSelf, PyObject* poArgs)
{
	BYTE iDSType;
	if (!PyTuple_GetInteger(poArgs, 0, &iDSType))
		return Py_BadArgument();

	CDragonSoulTable* dsTable = CItemManager::Instance().GetDragonSoulTable();
	if (!dsTable)
		return Py_BuildException("DragonSoulTable not initalized");

	return Py_BuildValue("i", dsTable->GetDSBasicApplyCount(iDSType));
}

PyObject* itemGetDSBasicApplyValue(PyObject* poSelf, PyObject* poArgs)
{
	BYTE iDSType;
	if (!PyTuple_GetInteger(poArgs, 0, &iDSType))
		return Py_BadArgument();

	WORD iApplyType;
	if (!PyTuple_GetInteger(poArgs, 1, &iApplyType))
		return Py_BadArgument();

	CDragonSoulTable* dsTable = CItemManager::Instance().GetDragonSoulTable();
	if (!dsTable)
		return Py_BuildException("DragonSoulTable not initalized");

	return Py_BuildValue("i", dsTable->GetDSBasicApplyValue(iDSType, iApplyType));
}

PyObject* itemGetDSAdditionalApplyValue(PyObject* poSelf, PyObject* poArgs)
{
	BYTE iDSType;
	if (!PyTuple_GetInteger(poArgs, 0, &iDSType))
		return Py_BadArgument();

	WORD iApplyType;
	if (!PyTuple_GetInteger(poArgs, 1, &iApplyType))
		return Py_BadArgument();

	CDragonSoulTable* dsTable = CItemManager::Instance().GetDragonSoulTable();
	if (!dsTable)
		return Py_BuildException("DragonSoulTable not initalized");

	return Py_BuildValue("i", dsTable->GetDSAdditionalApplyValue(iDSType, iApplyType));
}
#endif

search this:

		{ NULL,								NULL,									NULL		 },


add above this:

#ifdef ENABLE_DS_SET
		{ "GetDSSetWeight",					itemGetDSSetWeight,						METH_VARARGS },
		{ "GetDSBasicApplyCount",			itemGetDSBasicApplyCount,				METH_VARARGS },
		{ "GetDSBasicApplyValue",			itemGetDSBasicApplyValue,				METH_VARARGS },
		{ "GetDSAdditionalApplyValue",		itemGetDSAdditionalApplyValue,			METH_VARARGS },
#endif