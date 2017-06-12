#include "Main.h"

void Gui::onLoadFromFilePressed(tgui::EditBox::Ptr editbox)
{
	if (editbox->getText() == "File name")
	{
		editbox->setText("");
	}
}

Gui::Panel::Panel(tgui::Gui& gui, DrawFigures& loadedData):m_gui(gui),m_loadedData(loadedData){
}


void Gui::Panel::preparePanel()
{
	m_current_number = 0;

	figureNumber->setSize(140, 30);
	figureNumber->setPosition(5, 45);
	figureNumber->setText("Selected Figure");
	figureNumber->setTextSize(16);
	m_gui.add(figureNumber, "figureNumber");
		
	leftArrow->setSize(20, 30);
	leftArrow->setText("<");
	leftArrow->setPosition(65, 75);
	leftArrow->connect("pressed", &Gui::Panel::leftArrowPressed, this);
	m_gui.add(leftArrow, "leftArrow");

	rightArrow->setSize(20, 30);
	rightArrow->setText(">");
	rightArrow->setPosition(115, 75);
	rightArrow->connect("pressed", &Gui::Panel::rightArrowPressed, this);
	m_gui.add(rightArrow, "rightArrow");
	
	currentPosition->setSize(20, 30);
	currentPosition->setPosition(95, 80);
	currentPosition->setText("0"); 
	currentPosition->setTextSize(16);
	m_gui.add(currentPosition, "currentPosition");
	
	changeOrder->setSize(170, 30);
	changeOrder->setText("Change Layer Order");
	changeOrder->setPosition(15, 120);
	changeOrder->setTextSize(16);
	m_gui.add(changeOrder, "changeOrder");

	upArrow->setSize(20, 30);
	upArrow->setText("^");
	upArrow->setPosition(70, 145);
	m_gui.add(upArrow, "upArrow");

	downArrow->setSize(20, 30);
	downArrow->setText("v");
	downArrow->setPosition(110, 145);
	m_gui.add(downArrow, "downArrow");
	
	selectParameterToChange->setSize(180, 30);
	selectParameterToChange->setPosition(5, 190);
	selectParameterToChange->addItem("Change Color Line");
	selectParameterToChange->addItem("Change Fulfil Color");
	selectParameterToChange->addItem("Change Border Size");
	selectParameterToChange->addItem("Opacity");
	selectParameterToChange->addItem("Vertex Coords");
	m_gui.add(selectParameterToChange, "selectParameterToChange");

	changeValues->setSize(190, 30);
	changeValues->setPosition(5, 240);
	changeValues->setText("");
	changeValues->setTextSize(16);
	m_gui.add(changeValues, "changeValues");

	lineColorParameter->setSize(140, 60);
	lineColorParameter->setPosition(5, 290);
	lineColorParameter->setText("Line Color: \n\n");
	lineColorParameter->setTextSize(16);
	m_gui.add(lineColorParameter, "lineColorParameter");

	fulfilColorParameter->setSize(140, 60);
	fulfilColorParameter->setPosition(5, 340);
	fulfilColorParameter->setText("Fulfill Color: \n\n");
	fulfilColorParameter->setTextSize(16);
	m_gui.add(fulfilColorParameter, "fulfilColorParameter");

	borderSizeParameter->setSize(140, 60);
	borderSizeParameter->setPosition(5, 390);
	borderSizeParameter->setText("Border Size: \n\n");
	borderSizeParameter->setTextSize(16);
	m_gui.add(borderSizeParameter, "borderSizeParameter");

	opacityParameter->setSize(140, 60);
	opacityParameter->setPosition(5, 440);
	opacityParameter->setText("Opacity: \n\n");
	opacityParameter->setTextSize(16);
	m_gui.add(opacityParameter, "opacityParameter");

	vertexesParameter->setSize(140,150 );
	vertexesParameter->setPosition(5, 490);
	vertexesParameter->setText("Vertex Coords: \n\n");
	vertexesParameter->setTextSize(16);
	m_gui.add(vertexesParameter, "vertexesParameter");

	saveButton->setSize(170, 30);
	saveButton->setText("Save");
	saveButton->setPosition(15, 560);
	saveButton->setTextSize(14);
	m_gui.add(saveButton, "saveButton");
}

void Gui::Panel::updatePanel() {
	
	if (m_loadedData.GetCountOfElements()==0) {
		return ;
	}

	if (m_loadedData.GetFigureType(m_current_number) == 1) {
		updateLineColorInfo();
		updateFulfilColorInfo();
		updateBorderSize();
		updateOpacity();
		updateVertexes();
		if (selectParameterToChange->getSelectedItemIndex() == 0)
			std::cout << "tat";
	}
	if (m_loadedData.GetFigureType(m_current_number) == 2) {
		
		updateLineColorInfo();
		updateFulfilColorInfo();
		updateBorderSize();
		updateOpacity();
		updateVertexes();
	}
	if (m_loadedData.GetFigureType(m_current_number) == 3) {
		updateLineColorInfo();
		fulfilColorParameter->setText("");
		updateBorderSize();
		updateOpacity();
		updateVertexes();
	}
	
}

void Gui::Panel::leftArrowPressed() {
	if (m_current_number != 0) {

		m_current_number--;

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
	}

}
void Gui::Panel::rightArrowPressed() {
	if (m_current_number != m_loadedData.GetCountOfElements()-1) {

		m_current_number++;

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
	}
}

void Gui::Panel::updateLineColorInfo() {
	std::ostringstream ss;
	ss << "Line Color: \nR:";
	ss << m_loadedData.GetOutlineR(m_current_number);
	ss << " G:";
	ss << m_loadedData.GetOutlineG(m_current_number);
	ss << " B:";
	ss << m_loadedData.GetOutlineB(m_current_number);
	std::string tekst = ss.str();
	lineColorParameter->setText(tekst);
}

void Gui::Panel::updateFulfilColorInfo() {
	std::ostringstream ss;
	ss << "Fulfill Color: \nR:";
	ss << m_loadedData.GetInR(m_current_number);
	ss << " G:";
	ss << m_loadedData.GetInG(m_current_number);
	ss << " B:";
	ss << m_loadedData.GetInB(m_current_number);
	std::string tekst = ss.str();
	fulfilColorParameter->setText(tekst);
}

void Gui::Panel::updateBorderSize() {
	std::ostringstream ss;
	ss << "Border Size: \n";
	ss << m_loadedData.GetBorderSize(m_current_number);
	std::string tekst = ss.str();
	borderSizeParameter->setText(tekst);
}

void Gui::Panel::updateOpacity() {
	std::ostringstream ss;
	ss << "Opacity: \n";
	ss << m_loadedData.GetOpacity(m_current_number);
	std::string tekst = ss.str();
	opacityParameter->setText(tekst);
}

void Gui::Panel::updateVertexes() {
	std::ostringstream ss;
	ss << "Vertex Coords: \n";
	for (int i = 0; i < m_loadedData.GetVertexCount(m_current_number); i++) {
		ss << i;
		ss << ": ";
		ss << m_loadedData.GetPointX(m_current_number,i);
		ss << " ";
		ss << m_loadedData.GetPointY(m_current_number,i);
		ss << "\n";
	}
	std::string tekst = ss.str();
	vertexesParameter->setText(tekst);

}