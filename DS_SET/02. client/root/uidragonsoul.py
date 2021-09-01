before this:

		self.sellingSlotNumber = -1

add this:

		if app.ENABLE_DS_SET:
			self.wndAllMythOn = None

before this:

	def __del__(self):
		ui.ScriptWindow.__del__(self)

add this:

		if app.ENABLE_DS_SET:
			self.setGrade = 0

search this:

			wndEquip = self.GetChild("EquipmentSlot")

add below this:

			if app.ENABLE_DS_SET:
				self.wndAllMythOn = self.GetChild("all_myth_on")
				self.wndAllMythOn.Hide()

search this.

	def ShowToolTip(self, window_type, slotIndex):

overwrite the function with:

	def ShowToolTip(self, window_type, slotIndex):
		if None != self.tooltipItem:
			if player.INVENTORY == window_type:
				if app.ENABLE_DS_SET and player.IsDSEquipmentSlot(window_type, slotIndex):
					self.tooltipItem.SetInventoryItem(slotIndex, player.EQUIPMENT)
				else:
					self.tooltipItem.SetInventoryItem(slotIndex)
			else:
				self.tooltipItem.SetInventoryItem(slotIndex, player.DRAGON_SOUL_INVENTORY)

after this function:

	def SetDeckPage(self, page):

add this.

	if app.ENABLE_DS_SET:
		def SetDSSetGrade(self, grade):
			self.setGrade = grade
			# if self.wndAllMythOn:
				# self.wndAllMythOn.Show() if grade != 0 else self.wndAllMythOn.Hide()

		def GetDSSetGrade(self):
			if not self.isActivated:
				return 0

			return self.setGrade