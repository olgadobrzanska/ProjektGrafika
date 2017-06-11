#include "Main.h"


void loadGui(tgui::Gui& gui, DrawFigures& loadedData)
{
	tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt");
	
	tgui::EditBox::Ptr loadFromFilename = theme->load("Editbox");
	loadFromFilename->setSize(140, 30);
	loadFromFilename->setPosition(5, 5);
	loadFromFilename->setText("File name");
	loadFromFilename->setTextSize(14);
	gui.add(loadFromFilename, "loadFromFilename");

	tgui::Button::Ptr loadFromSubmit = theme->load("Button");
	loadFromSubmit->setSize(40, 30);
	loadFromSubmit->setText("Load");
	loadFromSubmit->setPosition(155, 5);
	gui.add(loadFromSubmit, "loadFromSubmit");

	loadFromSubmit->connect("pressed", &DrawFigures::LoadFromFile, &loadedData, loadFromFilename);
	loadFromFilename->connect("clicked", Gui::onLoadFromFilePressed, loadFromFilename);

}
void preparePanel(tgui::Gui& gui, DrawFigures& loadedData)
{
	tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt");
	
	tgui::Label::Ptr figureNumber = theme->load("Label");
	figureNumber->setSize(140, 30);
	figureNumber->setPosition(5, 55);
	figureNumber->setText("Selected Figure");
	figureNumber->setTextSize(16);
	gui.add(figureNumber, "figureNumber");

	tgui::Button::Ptr leftArrow = theme->load("Button");
	leftArrow->setSize(20, 30);
	leftArrow->setText("<");
	leftArrow->setPosition(25, 75);
	gui.add(leftArrow, "leftArrow");

	tgui::Button::Ptr rightArrow = theme->load("Button");
	rightArrow->setSize(20, 30);
	rightArrow->setText(">");
	rightArrow->setPosition(125,75);
	gui.add(rightArrow, "rightArrow");

	tgui::Label::Ptr currentPosition = theme->load("Label");
	currentPosition->setSize(20, 30);
	currentPosition->setPosition(75, 80);
	currentPosition->setText("0"); // tu nr warstwy
	currentPosition->setTextSize(16);
	gui.add(currentPosition, "currentPosition");

	tgui::Button::Ptr loadFromSubmit = theme->load("Button");
	loadFromSubmit->setSize(40, 30);
	loadFromSubmit->setText("Load");
	loadFromSubmit->setPosition(155, 5);
	gui.add(loadFromSubmit, "loadFromSubmit");

	
	tgui::Label::Ptr figureParameters = theme->load("Label");
	figureParameters->setSize(140, 200);
	figureParameters->setPosition(5, 105);
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

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	tgui::Gui gui(window);
	DrawFigures loadedData;
	sf::RectangleShape borderBox(sf::Vector2f(200., 0.));
	borderBox.setOutlineColor(sf::Color::Black);
	borderBox.setOutlineThickness(0.);
	borderBox.setFillColor(sf::Color::White);
	borderBox.setPosition(198., 0.);
	borderBox.setSize(sf::Vector2f(802., 600.));

preparePanel(gui, loadedData);
	try
	{
		loadGui(gui, loadedData);
	}
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI: " << e.what() << std::endl;
		return 1;
	}


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			gui.handleEvent(event);
		}

		window.clear();
		window.draw(borderBox);
		window.draw(loadedData);
		gui.draw();
		window.display();
	}


	return EXIT_SUCCESS;
}