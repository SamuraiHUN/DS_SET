search this:

		self.tooltipItem = uiToolTip.ItemToolTip()

add below this:

		if app.ENABLE_DS_SET:
			self.tooltipItem.BindInterface(self)

search this:

	def DragonSoulDeactivate(self):
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.DeactivateDragonSoul()

add below this:

	if app.ENABLE_DS_SET:
		def DragonSoulSetGrade(self, grade):
			self.wndDragonSoul.SetDSSetGrade(grade)