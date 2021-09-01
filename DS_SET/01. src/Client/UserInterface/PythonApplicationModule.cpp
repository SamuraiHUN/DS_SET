add this:

#ifdef ENABLE_DS_SET
	PyModule_AddIntConstant(poModule, "ENABLE_DS_SET", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_DS_SET", 0);
#endif

before this:

	PyModule_AddIntConstant(poModule, "VERSION", VERSION);
}