before this:

	if app.ENABLE_DRAGON_SOUL_SYSTEM:
		AFFECT_DATA_DICT[chr.NEW_AFFECT_DRAGON_SOUL_DECK1] = (localeInfo.TOOLTIP_DRAGON_SOUL_DECK1, "d:/ymir work/ui/dragonsoul/buff_ds_sky1.tga")
		AFFECT_DATA_DICT[chr.NEW_AFFECT_DRAGON_SOUL_DECK2] = (localeInfo.TOOLTIP_DRAGON_SOUL_DECK2, "d:/ymir work/ui/dragonsoul/buff_ds_land1.tga")

add this:

	if app.ENABLE_DS_SET:
		AFFECT_DATA_DICT[chr.NEW_AFFECT_DS_SET] = (localeInfo.TOOLTIP_DS_SET, "d:/ymir work/ui/dragonsoul/bonus_conjunto.tga")
