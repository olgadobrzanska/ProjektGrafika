#include "Main.h"


Gui::Panel::Panel(sf::RenderWindow& window, tgui::Gui& gui, DrawFigures& loadedData):m_window(window),m_gui(gui),m_loadedData(loadedData){
	preparePanel();
}


void Gui::Panel::preparePanel()
{
	m_current_number = 0;
	m_current_vertex = 0;

	tgui::EditBox::Ptr loadFromFilename = theme->load("Editbox");
	loadFromFilename->setSize(140, 30);
	loadFromFilename->setPosition(5, 5);
	loadFromFilename->setDefaultText("File name");
	loadFromFilename->setTextSize(14);
	m_gui.add(loadFromFilename, "loadFromFilename");

	tgui::Label::Ptr toolTip = theme->load("ToolTip");
	toolTip->setText("Demo file: data.txt");
	loadFromFilename->setToolTip(toolTip);

	tgui::Button::Ptr loadFromSubmit = theme->load("Button");
	loadFromSubmit->setSize(40, 30);
	loadFromSubmit->setText("Load");
	loadFromSubmit->setPosition(155, 5);
	m_gui.add(loadFromSubmit, "loadFromSubmit");

	loadFromSubmit->connect("pressed", &DrawFigures::LoadFromFile, &m_loadedData, loadFromFilename);


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
	selectParameterToChange->addItem("Change Outline Color");
	selectParameterToChange->addItem("Change Fill Color");
	selectParameterToChange->addItem("Change Border Size");
	selectParameterToChange->addItem("Opacity");
	selectParameterToChange->addItem("Vertex Coords");
	selectParameterToChange->addItem("Radius/Vertex #");
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

	figureName->setSize(140, 60);
	figureName->setPosition(5, 280);
	figureName->setText("");
	figureName->setTextSize(14);
	m_gui.add(figureName, "figureName");

	lineColorParameter->setSize(140, 60);
	lineColorParameter->setPosition(5, 300);
	lineColorParameter->setText("Outline Color: \n\n");
	lineColorParameter->setTextSize(14);
	m_gui.add(lineColorParameter, "lineColorParameter");

	fulfilColorParameter->setSize(140, 60);
	fulfilColorParameter->setPosition(5, 350);
	fulfilColorParameter->setText("Fill Color: \n\n");
	fulfilColorParameter->setTextSize(14);
	m_gui.add(fulfilColorParameter, "fulfilColorParameter");

	borderSizeParameter->setSize(140, 60);
	borderSizeParameter->setPosition(5, 400);
	borderSizeParameter->setText("Border Size: \n\n");
	borderSizeParameter->setTextSize(14);
	m_gui.add(borderSizeParameter, "borderSizeParameter");

	opacityParameter->setSize(140, 60);
	opacityParameter->setPosition(5, 450);
	opacityParameter->setText("Opacity: \n\n");
	opacityParameter->setTextSize(14);
	m_gui.add(opacityParameter, "opacityParameter");

	vertexesParameter->setSize(140,60 );
	vertexesParameter->setPosition(5, 500);
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

	saveButton->setSize(100, 30);
	saveButton->setText("Save to file");
	saveButton->setPosition(90, 555);
	saveButton->setTextSize(14);
	saveButton->connect("pressed", &Gui::Panel::saveButtonPressed, this);
	saveButton->disable(true);
	m_gui.add(saveButton, "saveButton");

	saveX->setSize(70, 20);
	saveX->setTextSize(10);
	saveX->setPosition(10, 550);
	saveX->setDefaultText("width");
	m_gui.add(saveX, "saveX");

	saveY->setSize(70, 20);
	saveY->setTextSize(10);
	saveY->setPosition(10, 570);
	saveY->setDefaultText("height");
	m_gui.add(saveY, "saveY");


	tgui::Label::Ptr toolTipSave = theme->load("ToolTip");
	toolTipSave->setText("Output: myresult.bmp");
	tgui::ToolTip::setDistanceToMouse({ 30, -8 });
	tgui::ToolTip::setTimeToDisplay(sf::milliseconds(100));
	saveButton->setToolTip(toolTipSave);

	tgui::Label::Ptr toolTipSaveX = theme->load("ToolTip");
	toolTipSaveX->setText("Value between 20 and 20000");
	saveX->setToolTip(toolTipSaveX);
	saveY->setToolTip(toolTipSaveX);
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
		if (saveX->isEnabled())
			saveX->disable();
		if (saveY->isEnabled())
			saveY->disable();
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
	if (!saveX->isEnabled())
		saveX->enable();
	if (!saveY->isEnabled())
		saveY->enable();
	if (!upArrowVertex->isEnabled())
		upArrowVertex->enable();
	if (!downArrowVertex->isEnabled())
		downArrowVertex->enable();

	if (m_loadedData.GetFigureType(m_current_number) == 3)
		fulfilColorParameter->setText("");
	else
		updateFillColorInfo();
	updateOutlineColorInfo();
	updateBorderSize();
	updateOpacity();
	updateVertexes();
	updateFigureName();
	checkParameterToChange();
}

void Gui::Panel::leftArrowPressed() {
	if (m_current_number != 0) {

		m_current_number--;
		m_current_vertex = 0;
		m_loadedData.blinkFigure(m_current_number);

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
		changeValues->setText("");
		selectParameterToChange->setSelectedItemByIndex(-1);
	}

}
void Gui::Panel::rightArrowPressed() {
	if (m_current_number != m_loadedData.GetCountOfElements()-1) {

		m_current_number++;
		m_current_vertex = 0;
		m_loadedData.blinkFigure(m_current_number);

		std::ostringstream ss;
		ss << m_current_number;
		std::string tekst = ss.str();
		currentPosition->setText(tekst);
		changeValues->setText("");
		selectParameterToChange->setSelectedItemByIndex(-1);
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
		ss << m_loadedData.GetPointY(m_current_number, m_current_vertex);
		std::string tekst = ss.str();
		vertexesParameter->setText(tekst);
	}
}

void Gui::Panel::updateFigureName()
{
	std::string figurename;
	if (m_loadedData.GetCountOfElements() != 0)
		switch (m_loadedData.GetFigureType(m_current_number))
		{
		case 1:
			figurename = "Circle";
			break;
		case 2:
			figurename = "Rectangle";
			break;
		case 3:
			figurename = "Line";
			break;
		case 4:
			figurename = "Polygon";
			break;
		case 5:
			figurename = "Plain polygon";
			break;
		default:
			figurename = "";
		}
	else
		figurename = "";
	figureName->setTextStyle(sf::Text::Bold);
	figureName->setText(figurename);
}

void Gui::Panel::updateOutlineColorInfo()
{
	std::ostringstream ss;
	ss << "Outline Color: \nR:";
	ss << m_loadedData.GetOutlineR(m_current_number);
	ss << " G:";
	ss << m_loadedData.GetOutlineG(m_current_number);
	ss << " B:";
	ss << m_loadedData.GetOutlineB(m_current_number);
	std::string tekst = ss.str();
	lineColorParameter->setText(tekst);
}

void Gui::Panel::updateFillColorInfo() 
{
	std::ostringstream ss;
	ss << "Fill Color: \nR:";
	ss << m_loadedData.GetInR(m_current_number);
	ss << " G:";
	ss << m_loadedData.GetInG(m_current_number);
	ss << " B:";
	ss << m_loadedData.GetInB(m_current_number);
	std::string tekst = ss.str();
	fulfilColorParameter->setText(tekst);
}

void Gui::Panel::updateBorderSize() 
{
	std::ostringstream ss;
	ss << "Border Size: \n";
	ss << m_loadedData.GetBorderSize(m_current_number);
	std::string tekst = ss.str();
	borderSizeParameter->setText(tekst);
}

void Gui::Panel::updateOpacity() 
{
	std::ostringstream ss;
	ss << "Opacity: \n";
	ss << m_loadedData.GetOpacity(m_current_number);
	std::string tekst = ss.str();
	opacityParameter->setText(tekst);
}

void Gui::Panel::updateVertexes() 
{
	
	std::ostringstream ss;
	if (m_loadedData.GetFigureType(m_current_number) == DrawFigures::POLYGONCIRCLE && m_current_vertex == 1)
		ss << "Radius / Vertexes: \n";
	else
		ss << "Vertex Coords : \n";
	ss << m_current_vertex+1;
	ss << ": ";
	ss << m_loadedData.GetPointX(m_current_number,m_current_vertex);
	ss << " ";
	ss << m_loadedData.GetPointY(m_current_number, m_current_vertex);
	std::string tekst = ss.str();
	vertexesParameter->setText(tekst);
}

void Gui::Panel::checkParameterToChange() 
{
	
	if (selectParameterToChange->getSelectedItemIndex() == 0) {
		changeValues->setDefaultText("R G B");
	}
	if (selectParameterToChange->getSelectedItemIndex() == 1) {
		if (m_loadedData.GetFigureType(m_current_number) == DrawFigures::LINE)
			selectParameterToChange->setSelectedItemByIndex(-1);
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
	if (selectParameterToChange->getSelectedItemIndex() == 5)
	{
		if (m_loadedData.GetFigureType(m_current_number) != DrawFigures::POLYGONCIRCLE)
			selectParameterToChange->setSelectedItemByIndex(-1);
		changeValues->setDefaultText("Radius/Vertexes #");
	}
}

void Gui::Panel::refreshButtonPressed() 
{
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
	if (selectParameterToChange->getSelectedItemIndex() == 5)
	{
		int newX, newY;
		std::istringstream iss(changeValues->getText());
		iss >> newX >> newY;
		if (!iss)
			return;
		m_loadedData.SetPointX(newX, m_current_number, 1);
		m_loadedData.SetPointY(newY, m_current_number, 1);
		
	}
}

void Gui::Panel::saveButtonPressed() const
{
	std::istringstream issx(saveX->getText()), issy(saveY->getText());
	int x_size, y_size;
	issx >> x_size; issy >> y_size;
	if (!issx || !issy)
		return;

	if (x_size < 20 || x_size > 20000 || y_size < 20 || y_size > 20000)
		return;

	using namespace cimg_library;

	sf::Texture texture;
	sf::Vector2u getWindowSize = m_window.getSize();
	texture.create(getWindowSize.x, getWindowSize.y);
	texture.update(m_window);

	sf::Image screenshot = texture.copyToImage();
	texture.loadFromImage(screenshot, sf::IntRect(200, 0, 999, 599));
	screenshot = texture.copyToImage();
	screenshot.saveToFile("temporary.bmp");
	CImg<unsigned char> image("temporary.bmp");
	std::remove("temporary.bmp");
	image.resize(x_size, y_size);
	image.save_bmp("myresult.bmp");
	
	saveX->setText(""); saveY->setText("");
}
