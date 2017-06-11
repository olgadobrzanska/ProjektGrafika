#include "Main.h"

void Gui::onLoadFromFilePressed(tgui::EditBox::Ptr editbox)
{
	if (editbox->getText() == "File name")
	{
		editbox->setText("");
	}
}

void Gui::preparePanel(tgui::Gui& gui, DrawFigures& loadedData)
{
	tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt");

	tgui::Label::Ptr figureNumber = theme->load("Label");
	figureNumber->setSize(140, 30);
	figureNumber->setPosition(5, 45);
	figureNumber->setText("Selected Figure");
	figureNumber->setTextSize(16);
	gui.add(figureNumber, "figureNumber");

	tgui::Button::Ptr leftArrow = theme->load("Button");
	leftArrow->setSize(20, 30);
	leftArrow->setText("<");
	leftArrow->setPosition(65, 75);
	gui.add(leftArrow, "leftArrow");

	tgui::Button::Ptr rightArrow = theme->load("Button");
	rightArrow->setSize(20, 30);
	rightArrow->setText(">");
	rightArrow->setPosition(115, 75);
	gui.add(rightArrow, "rightArrow");

	tgui::Label::Ptr currentPosition = theme->load("Label");
	currentPosition->setSize(20, 30);
	currentPosition->setPosition(95, 80);
	currentPosition->setText("0"); // tu nr warstwy
	currentPosition->setTextSize(16);
	gui.add(currentPosition, "currentPosition");
	
	tgui::Label::Ptr changeOrder = theme->load("Label");
	changeOrder->setSize(170, 30);
	changeOrder->setText("Change Layer Order");
	changeOrder->setPosition(15, 120);
	changeOrder->setTextSize(16);
	gui.add(changeOrder, "changeOrder");

	tgui::Button::Ptr upArrow = theme->load("Button");
	upArrow->setSize(20, 30);
	upArrow->setText("^");
	upArrow->setPosition(70, 145);
	gui.add(upArrow, "upArrow");

	tgui::Button::Ptr downArrow = theme->load("Button");
	downArrow->setSize(20, 30);
	downArrow->setText("v");
	downArrow->setPosition(110, 145);
	gui.add(downArrow, "downArrow");
	

	//////////////////////////////

	tgui::Label::Ptr figureParameters = theme->load("Label");
	figureParameters->setSize(140, 150);
	figureParameters->setPosition(5, 180);
	figureParameters->setText("Line Color: \n\nFulfill color: \n\nLine Size: \n\nVertex Position: \n\n");
	figureParameters->setTextSize(16);
	gui.add(figureParameters, "figureParameters");

	tgui::Button::Ptr changeLineColor = theme->load("Button");
	changeLineColor->setSize(170, 30);
	changeLineColor->setText("Change line color");
	changeLineColor->setPosition(15, 360);
	changeLineColor->setTextSize(14);
	gui.add(changeLineColor, "changeLineColor");

	

	tgui::Button::Ptr changeFulfillColor = theme->load("Button");
	changeFulfillColor->setSize(170, 30);
	changeFulfillColor->setText("Change fulfill color");
	changeFulfillColor->setPosition(15, 410);
	changeLineColor->setTextSize(14);
	gui.add(changeFulfillColor, "changeFulfillColor");

	tgui::Button::Ptr changeLineSize = theme->load("Button");
	changeLineSize->setSize(170, 30);
	changeLineSize->setText("Change line size");
	changeLineSize->setPosition(15, 460);
	changeLineSize->setTextSize(14);
	gui.add(changeLineSize, "changeLineSize");

	tgui::Button::Ptr changeVertexPosition = theme->load("Button");
	changeVertexPosition->setSize(170, 30);
	changeVertexPosition->setText("Change Vertex Position");
	changeVertexPosition->setPosition(15, 510);
	changeVertexPosition->setTextSize(14);
	gui.add(changeVertexPosition, "changeVertexPosition");

	tgui::Button::Ptr saveButton = theme->load("Button");
	saveButton->setSize(170, 30);
	saveButton->setText("Save");
	saveButton->setPosition(15, 560);
	saveButton->setTextSize(14);
	gui.add(saveButton, "saveButton");
}