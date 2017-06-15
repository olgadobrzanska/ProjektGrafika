#include "Main.h"


Gui::Panel::Panel(sf::RenderWindow& window, tgui::Gui& gui, DrawFigures& loadedData):m_window(window),m_gui(gui),m_loadedData(loadedData){
}


void Gui::Panel::preparePanel()
{
	m_current_number = 0;
	m_current_vertex = 0;



	figureNumber->setSize(140, 30);
	figureNumber->setPosition(5, 45);
	figureNumber->setText("Selected Figure");
	figureNumber->setTextSize(14);
	m_gui.add(figureNumber, "figureNumber");
		
	leftArrow->setSize(20, 20);
	leftArrow->setText("<");
	leftArrow->setPosition(65, 70);
	leftArrow->connect("pressed", &Gui::Panel::leftArrowPressed, this);
	leftArrow->disable(true);
	m_gui.add(leftArrow, "leftArrow");

	rightArrow->setSize(20, 20);
	rightArrow->setText(">");
	rightArrow->setPosition(115, 70);
	rightArrow->connect("pressed", &Gui::Panel::rightArrowPressed, this);
	rightArrow->disable(true);
	m_gui.add(rightArrow, "rightArrow");
	
	currentPosition->setSize(20, 20);
	currentPosition->setPosition(95, 70);
	currentPosition->setText("0"); 
	currentPosition->setTextSize(16);
	m_gui.add(currentPosition, "currentPosition");
	
	changeOrder->setSize(170, 30);
	changeOrder->setText("Change Layer Order");
	changeOrder->setPosition(5, 100);
	changeOrder->setTextSize(14);
	m_gui.add(changeOrder, "changeOrder");

	upArrow->setSize(20, 20);
	upArrow->setText("^");
	upArrow->setPosition(70, 130);
	upArrow->connect("pressed", &Gui::Panel::upArrowPressed, this);
	upArrow->disable(true);
	m_gui.add(upArrow, "upArrow");

	downArrow->setSize(20, 20);
	downArrow->setText("v");
	downArrow->setPosition(110, 130);
	downArrow->connect("pressed", &Gui::Panel::downArrowPressed, this);
	downArrow->disable(true);
	m_gui.add(downArrow, "downArrow");
	
	selectParameterToChange->setSize(190, 30);
	selectParameterToChange->setPosition(5, 160);
	selectParameterToChange->setTextSize(12);
	selectParameterToChange->addItem("Change Color Line");
	selectParameterToChange->addItem("Change Fulfil Color");
	selectParameterToChange->addItem("Change Border Size");
	selectParameterToChange->addItem("Opacity");
	selectParameterToChange->addItem("Vertex Coords");
	selectParameterToChange->disable(true);
	m_gui.add(selectParameterToChange, "selectParameterToChange");
	
	
	
	changeValues->setSize(190, 30);
	changeValues->setPosition(5, 200);
	changeValues->setText("");
	changeValues->setTextSize(14);
	changeValues->disable(true);
	m_gui.add(changeValues, "changeValues");
	

	refreshButton->setSize(110, 30);
	refreshButton->setText("Refresh");
	refreshButton->setPosition(45, 240);
	refreshButton->setTextSize(14);
	refreshButton->connect("pressed", &Gui::Panel::refreshButtonPressed, this);
	refreshButton->disable(true);
	m_gui.add(refreshButton, "refreshButton");

	lineColorParameter->setSize(140, 60);
	lineColorParameter->setPosition(5, 280);
	lineColorParameter->setText("Line Color: \n\n");
	lineColorParameter->setTextSize(14);
	m_gui.add(lineColorParameter, "lineColorParameter");

	fulfilColorParameter->setSize(140, 60);
	fulfilColorParameter->setPosition(5, 330);
	fulfilColorParameter->setText("Fulfill Color: \n\n");
	fulfilColorParameter->setTextSize(14);
	m_gui.add(fulfilColorParameter, "fulfilColorParameter");

	borderSizeParameter->setSize(140, 60);
	borderSizeParameter->setPosition(5, 380);
	borderSizeParameter->setText("Border Size: \n\n");
	borderSizeParameter->setTextSize(14);
	m_gui.add(borderSizeParameter, "borderSizeParameter");

	opacityParameter->setSize(140, 60);
	opacityParameter->setPosition(5, 430);
	opacityParameter->setText("Opacity: \n\n");
	opacityParameter->setTextSize(14);
	m_gui.add(opacityParameter, "opacityParameter");

	vertexesParameter->setSize(140,60 );
	vertexesParameter->setPosition(5, 480);
	vertexesParameter->setText("Vertex Coords: \n\n");
	vertexesParameter->setTextSize(14);
	m_gui.add(vertexesParameter, "vertexesParameter");

	upArrowVertex->setSize(20, 20);
	upArrowVertex->setText("^");
	upArrowVertex->setPosition(160, 500);
	upArrowVertex->connect("pressed", &Gui::Panel::upArrowVertexPressed, this);
	upArrowVertex->disable(true);
	m_gui.add(upArrowVertex, "upArrowVertex");

	downArrowVertex->setSize(20, 20);
	downArrowVertex->setText("v");
	downArrowVertex->setPosition(160, 520);
	downArrowVertex->connect("pressed", &Gui::Panel::downArrowVertexPressed, this);
	downArrowVertex->disable(true);
	m_gui.add(downArrowVertex, "downArrowVertex");

	saveButton->setSize(110, 30);
	saveButton->setText("Save");
	saveButton->setPosition(45, 560);
	saveButton->setTextSize(14);
	saveButton->connect("pressed", &Gui::Panel::saveButtonPressed, this);
	saveButton->disable(true);
	m_gui.add(saveButton, "saveButton");
}

void Gui::Panel::updatePanel() {
	
	if (m_loadedData.GetCountOfElements()==0) {
		if (changeValues->isEnabled())
			changeValues->disable();
		if (selectParameterToChange->isEnabled())
			selectParameterToChange->disable();
		if (leftArrow->isEnabled())
			leftArrow->disable();
		if (rightArrow->isEnabled())
			rightArrow->disable();
		if (downArrow->isEnabled())
			downArrow->disable();
		if (upArrow->isEnabled())
			upArrow->disable();
		if (refreshButton->isEnabled())
			refreshButton->disable();
		if (saveButton->isEnabled())
			saveButton->disable();
		if (upArrowVertex->isEnabled())
			upArrowVertex->disable();
		if (downArrowVertex->isEnabled())
			downArrowVertex->disable();
		return ;
	}

	if (!changeValues->isEnabled())
		changeValues->enable();
	if (!selectParameterToChange->isEnabled())
		selectParameterToChange->enable();
	if (!leftArrow->isEnabled())
		leftArrow->enable();
	if (!rightArrow->isEnabled())
		rightArrow->enable();
	if (!downArrow->isEnabled())
		downArrow->enable();
	if (!upArrow->isEnabled())
		upArrow->enable();
	if (!refreshButton->isEnabled())
		refreshButton->enable();
	if (!saveButton->isEnabled())
		saveButton->enable();
	if (!upArrowVertex->isEnabled())
		upArrowVertex->enable();
	if (!downArrowVertex->isEnabled())
		downArrowVertex->enable();

	if (m_loadedData.GetFigureType(m_current_number) == 1) {
		updateLineColorInfo();
		updateFulfilColorInfo();
		updateBorderSize();
		updateOpacity();
		updateVertexes();
		checkParameterToChange();
	}
	if (m_loadedData.GetFigureType(m_current_number) == 2) {
		
		updateLineColorInfo();
		updateFulfilColorInfo();
		updateBorderSize();
		updateOpacity();
		updateVertexes();
		checkParameterToChange();
	}
	if (m_loadedData.GetFigureType(m_current_number) == 3) {
		updateLineColorInfo();
		fulfilColorParameter->setText("");
		updateBorderSize();
		updateOpacity();
		updateVertexes();
		checkParameterToChange();
	}
	if (m_loadedData.GetFigureType(m_current_number) == 4) {
		updateLineColorInfo();
		updateFulfilColorInfo();
		updateBorderSize();
		updateOpacity();
		updateVertexes();
		checkParameterToChange();
	}
	
}

void Gui::Panel::leftArrowPressed() {
	if (m_current_number != 0) {

		m_current_number--;
		m_current_vertex = 0;

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
	}

}
void Gui::Panel::rightArrowPressed() {
	if (m_current_number != m_loadedData.GetCountOfElements()-1) {

		m_current_number++;
		m_current_vertex = 0;

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
	}
}

void Gui::Panel::upArrowPressed() {
	if (m_current_number < m_loadedData.GetCountOfElements() - 1) {
		m_loadedData.ChangeLayers(m_current_number, true);
		m_current_number++;

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
	}
		
}

void Gui::Panel::downArrowPressed() {
	if (m_current_number >=1) {
		m_loadedData.ChangeLayers(m_current_number, false);
		m_current_number--;

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
	}
}

void Gui::Panel::upArrowVertexPressed() {
	if (m_current_vertex >0) {
		m_current_vertex--;
		std::ostringstream ss;
		ss << m_current_vertex + 1;
		ss << ": ";
		ss << m_loadedData.GetPointX(m_current_number, m_current_vertex);
		ss << " ";
		ss << m_loadedData.GetPointY(m_current_number, m_current_vertex);
		std::string tekst = ss.str();
		vertexesParameter->setText(tekst);
	}

}
void Gui::Panel::downArrowVertexPressed() {
	
	if (m_current_vertex<m_loadedData.GetVertexCount(m_current_number) - 1) {
		m_current_vertex++;
		std::ostringstream ss;
		ss << m_current_vertex + 1;
		ss << ": ";
		ss << m_loadedData.GetPointX(m_current_number, m_current_vertex);
		ss << " ";
		ss << m_loadedData.GetPointY(m_current_number, m_current_vertex);		std::string tekst = ss.str();
		vertexesParameter->setText(tekst);
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
	ss << "Vertex Coords : \n";
	ss << m_current_vertex+1;
	ss << ": ";
	ss << m_loadedData.GetPointX(m_current_number,m_current_vertex);
	ss << " ";
	ss << m_loadedData.GetPointY(m_current_number, m_current_vertex);
	std::string tekst = ss.str();
	vertexesParameter->setText(tekst);
}

void Gui::Panel::checkParameterToChange() {
	
	if (selectParameterToChange->getSelectedItemIndex() == 0) {
		changeValues->setDefaultText("R G B");
	}
	if (selectParameterToChange->getSelectedItemIndex() == 1) {
		if (m_loadedData.GetFigureType(m_current_number) == DrawFigures::LINE)
			selectParameterToChange->setSelectedItemByIndex(0);
		changeValues->setDefaultText("R G B");
	}
	if (selectParameterToChange->getSelectedItemIndex() == 2) {
		changeValues->setDefaultText("size");
	}
	if (selectParameterToChange->getSelectedItemIndex() == 3) {
		changeValues->setDefaultText("opacity");
	}
	if (selectParameterToChange->getSelectedItemIndex() == 4) {
		changeValues->setDefaultText("index x y");
	}
}

void Gui::Panel::refreshButtonPressed() {
	if (selectParameterToChange->getSelectedItemIndex() == 0) {
		if (changeValues->getText() != "") {
			int valueR, valueG, valueB;
			std::istringstream iss(changeValues->getText());
			iss >> valueR >> valueG >> valueB;
			if (!iss)
				return;
			m_loadedData.SetOutlineR(valueR, m_current_number);
			m_loadedData.SetOutlineG(valueG, m_current_number);
			m_loadedData.SetOutlineB(valueB, m_current_number);
			changeValues->setText("");
		}
	}
	if (selectParameterToChange->getSelectedItemIndex() == 1) {
		if (changeValues->getText() != "") {
			int valueR, valueG, valueB;
			std::istringstream iss(changeValues->getText());
			iss >> valueR >> valueG >> valueB;
			if (!iss)
				return;
			m_loadedData.SetInR(valueR, m_current_number);
			m_loadedData.SetInG(valueG, m_current_number);
			m_loadedData.SetInB(valueB, m_current_number);
			changeValues->setText("");
		}
	}
	if (selectParameterToChange->getSelectedItemIndex() == 2) {
		if (changeValues->getText() != "") {
			int value;
			std::istringstream iss(changeValues->getText());
			iss >> value;
			if (!iss)
				return;
			m_loadedData.SetBorderSize(value, m_current_number);
			changeValues->setText("");
		}
	}
	if (selectParameterToChange->getSelectedItemIndex() == 3) {
		if (changeValues->getText() != "") {
			int value;
			std::istringstream iss(changeValues->getText());
			iss >> value;
			if (!iss)
				return;
			m_loadedData.SetOpacity(value, m_current_number);
			changeValues->setText("");
		}
	}
	if (selectParameterToChange->getSelectedItemIndex() == 4) {
		if (changeValues->getText() != "") {
			int pointID, newX, newY;
			std::istringstream iss(changeValues->getText());
			iss >> pointID >> newX >> newY;
			if (!iss)
				return;
			m_loadedData.SetPointX(newX, m_current_number,pointID-1);
			m_loadedData.SetPointY(newY, m_current_number,pointID-1);
		}
	}
}

void Gui::Panel::saveButtonPressed() const
{
	sf::Texture texture;
	sf::Vector2u getWindowSize = m_window.getSize();
	texture.create(getWindowSize.x, getWindowSize.y);
	texture.update(m_window);
	sf::Image screenshot = texture.copyToImage();
	screenshot.saveToFile("myresult.png");
	texture.loadFromFile("myresult.png", sf::IntRect(200, 0, 999, 599));
	screenshot = texture.copyToImage();
	std::remove("myresult.png");
	screenshot.saveToFile("myresult.bmp");
}
