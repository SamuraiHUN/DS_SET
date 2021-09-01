add this import:

if app.ENABLE_DS_SET:
	import uiDragonSoul

search this:

	PRICE_INFO_COLOR = grp.GenerateColor((255.0/255.0), (255.0/255.0), (102.0/255.0), 1.0)

below add this.

	if app.ENABLE_DS_SET:
		TEXTLINE_2ND_COLOR_DEFAULT = grp.GenerateColor(1.0, 1.0, 0.6078, 1.0)

search this:

		self.defFontName = localeInfo.UI_DEF_FONT
		self.ClearToolTip()

above add this:

		if app.ENABLE_DS_SET:
			self.window_type = player.INVENTORY

search this:

	def AppendTextLine(self, text, color = FONT_COLOR, centerAlign = True):

add after the function:

	if app.ENABLE_DS_SET:
		def AppendTwoColorTextLine(self, text, color, text2, color2 = TEXTLINE_2ND_COLOR_DEFAULT, centerAlign = True):
			textLine = ui.TextLine()
			textLine.SetParent(self)
			textLine.SetFontName(self.defFontName)
			textLine.SetPackedFontColor(color)
			textLine.SetText(text)
			textLine.SetOutline()
			textLine.SetFeather(False)
			textLine.Show()

			textLine2 = ui.TextLine()
			textLine2.SetParent(textLine)
			textLine2.SetFontName(self.defFontName)
			textLine2.SetPackedFontColor(color2)
			textLine2.SetText(text2)
			textLine2.SetOutline()
			textLine2.SetFeather(False)
			textLine2.Show()

			w, h = textLine.GetTextSize()
			w2, h2 = textLine2.GetTextSize()

			if centerAlign:
				textLine.SetPosition(self.toolTipWidth / 2 - w2 / 2, self.toolTipHeight)
				textLine.SetHorizontalAlignCenter()
				textLine2.SetPosition(w / 2, 0)
			else:
				textLine.SetPosition(10, self.toolTipHeight)

			self.childrenList.append(textLine)
			self.childrenList.append(textLine2)

			self.toolTipHeight += self.TEXT_LINE_HEIGHT
			self.ResizeToolTip()

			return textLine

after this:

		self.isShopItem = False

add this:

		if app.ENABLE_DS_SET:
			self.interface = None

before this:

	def SetCannotUseItemForceSetDisableColor(self, enable):

add this:

	if app.ENABLE_DS_SET:
		def BindInterface(self, interface):
			from _weakref import proxy
			self.interface = proxy(interface)

after this:

	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):


add this:

		if app.ENABLE_DS_SET:
			self.window_type = window_type

before this:

	def __GetAttributeColor(self, index, value):

add this:

	if app.ENABLE_DS_SET:
		def __AppendDragonSoulAttributeInformation(self, attrSlot, dsType = 0, setGrade = 0):
			if 0 != attrSlot:
				if setGrade != 0:
					setWeightValue = item.GetDSSetWeight(setGrade)
					basicApplyCount = item.GetDSBasicApplyCount(dsType)

					for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
						type = attrSlot[i][0]
						value = attrSlot[i][1]

						if 0 == value:
							continue

						affectString = self.__GetAffectString(type, value)
						if affectString:
							affectColor = self.__GetAttributeColor(i, value)

							setValue = 0
							if i < basicApplyCount:
								setValue = item.GetDSBasicApplyValue(dsType, type)
							else:
								setValue = item.GetDSAdditionalApplyValue(dsType, type)

							if setValue != 0:
								setValue = (setValue * setWeightValue - 1) / 100 + 1
								if affectString.find('%') == -1:
									self.AppendTextLine("{} {}".format(affectString, "|cffffff9b(+{})".format(setValue)), affectColor)
								else:
									self.AppendTextLine("{} {}".format(affectString, "|cffffff9b(+{}%)".format(setValue)), affectColor)
							else:
								self.AppendTextLine(affectString, affectColor)
				else:
					for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
						type = attrSlot[i][0]
						value = attrSlot[i][1]

						if 0 == value:
							continue

						affectString = self.__GetAffectString(type, value)
						if affectString:
							affectColor = self.__GetAttributeColor(i, value)
							self.AppendTextLine(affectString, affectColor)

search this:

		elif item.ITEM_TYPE_DS == itemType:

change with:

		elif item.ITEM_TYPE_DS == itemType:
			self.AppendTextLine(self.__DragonSoulInfoString(itemVnum))

			if app.ENABLE_DS_SET:
				if self.window_type == player.EQUIPMENT and self.interface and self.interface.wndDragonSoul:
					self.__AppendDragonSoulAttributeInformation(attrSlot, itemVnum / 10000, self.interface.wndDragonSoul.GetDSSetGrade())
				else:
					self.__AppendDragonSoulAttributeInformation(attrSlot)
			else:
				self.__AppendAttributeInformation(attrSlot)
		else:
			self.__AppendLimitInformation()

