search this:

			elif chr.NEW_AFFECT_DRAGON_SOUL_QUALIFIED == type:
				self.BINARY_DragonSoulGiveQuilification()

add below this

			elif app.ENABLE_DS_SET and chr.NEW_AFFECT_DS_SET == type:
				self.interface.DragonSoulSetGrade(value)


search this:

		if chr.NEW_AFFECT_DRAGON_SOUL_DECK1 == type or chr.NEW_AFFECT_DRAGON_SOUL_DECK2 == type:
			self.interface.DragonSoulDeactivate()

add below this:

		elif app.ENABLE_DS_SET and chr.NEW_AFFECT_DS_SET == type:
			self.interface.DragonSoulSetGrade(0)