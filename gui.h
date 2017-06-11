#pragma once
#include "DrawFigures.h"
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Gui
{
	void onLoadFromFilePressed(tgui::EditBox::Ptr editbox);
	void preparePanel(tgui::Gui& gui, DrawFigures& loadedData);

}