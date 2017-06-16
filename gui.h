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
		Panel(sf::RenderWindow& window, tgui::Gui& gui, DrawFigures& loadedData);

		void preparePanel();
		void updatePanel();
		void leftArrowPressed();
		void rightArrowPressed();
		void upArrowVertexPressed();
		void downArrowVertexPressed();
		void updateFigureName();
		void updateLineColorInfo();
		void updateFulfilColorInfo();
		void updateBorderSize();
		void updateOpacity();
		void updateVertexes();
		void checkParameterToChange();
		void refreshButtonPressed();
		void upArrowPressed();
		void downArrowPressed();
		void saveButtonPressed() const;

	private:
		sf::RenderWindow& m_window;
		tgui::Gui& m_gui;
		DrawFigures& m_loadedData;
		tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt");
		int m_current_number;
		int m_current_vertex;

		tgui::EditBox::Ptr changeValues = theme->load("Editbox");
		tgui::ComboBox::Ptr selectParameterToChange = theme->load("ComboBox");
		tgui::Label::Ptr figureNumber = theme->load("Label");
		tgui::Button::Ptr leftArrow = theme->load("Button");
		tgui::Button::Ptr rightArrow = theme->load("Button");
		tgui::Label::Ptr currentPosition = theme->load("Label");
		tgui::Label::Ptr changeOrder = theme->load("Label");
		tgui::Button::Ptr downArrow = theme->load("Button");
		tgui::Button::Ptr upArrow = theme->load("Button");
		tgui::Label::Ptr figureName = theme->load("Label");
		tgui::Label::Ptr lineColorParameter = theme->load("Label");
		tgui::Label::Ptr fulfilColorParameter = theme->load("Label");
		tgui::Label::Ptr borderSizeParameter = theme->load("Label");
		tgui::Label::Ptr opacityParameter = theme->load("Label");
		tgui::Label::Ptr vertexesParameter = theme->load("Label");
		tgui::Button::Ptr refreshButton = theme->load("Button");
		tgui::Button::Ptr upArrowVertex = theme->load("Button");
		tgui::Button::Ptr downArrowVertex = theme->load("Button");
		tgui::Button::Ptr saveButton = theme->load("Button");
	};

}