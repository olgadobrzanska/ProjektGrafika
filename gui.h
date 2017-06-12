#pragma once
#include "DrawFigures.h"
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

namespace Gui
{
	class Panel {
	public:
		Panel(tgui::Gui& gui, DrawFigures& loadedData);

		void preparePanel();
		void updatePanel();
		void leftArrowPressed();
		void rightArrowPressed();
		void updateLineColorInfo();
		void updateFulfilColorInfo();
		void updateBorderSize();
		void updateOpacity();
		void updateVertexes();

	private:
		tgui::Gui& m_gui;
		DrawFigures& m_loadedData;
		tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt");
		int m_current_number;


		tgui::ComboBox::Ptr selectParameterToChange = theme->load("ComboBox");
		tgui::Label::Ptr figureNumber = theme->load("Label");
		tgui::Button::Ptr leftArrow = theme->load("Button");
		tgui::Button::Ptr rightArrow = theme->load("Button");
		tgui::Label::Ptr currentPosition = theme->load("Label");
		tgui::Label::Ptr changeOrder = theme->load("Label");
		tgui::Button::Ptr downArrow = theme->load("Button");
		tgui::Button::Ptr upArrow = theme->load("Button");
		//tgui::Label::Ptr figureParameters = theme->load("Label");
		tgui::Label::Ptr lineColorParameter = theme->load("Label");
		tgui::Label::Ptr fulfilColorParameter = theme->load("Label");
		tgui::Label::Ptr borderSizeParameter = theme->load("Label");
		tgui::Label::Ptr opacityParameter = theme->load("Label");
		tgui::Label::Ptr vertexesParameter = theme->load("label");
		tgui::EditBox::Ptr changeValues = theme->load("Editbox");


		tgui::Button::Ptr saveButton = theme->load("Button");
	};
	void onLoadFromFilePressed(tgui::EditBox::Ptr editbox);

}