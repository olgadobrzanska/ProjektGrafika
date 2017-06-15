#include "Main.h"


void loadGui(tgui::Gui& gui, DrawFigures& loadedData)
{
	tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt");
	
	tgui::EditBox::Ptr loadFromFilename = theme->load("Editbox");
	loadFromFilename->setSize(140, 30);
	loadFromFilename->setPosition(5, 5);
	loadFromFilename->setDefaultText("File name");
	loadFromFilename->setTextSize(14);
	gui.add(loadFromFilename, "loadFromFilename");

	tgui::Button::Ptr loadFromSubmit = theme->load("Button");
	loadFromSubmit->setSize(40, 30);
	loadFromSubmit->setText("Load");
	loadFromSubmit->setPosition(155, 5);
	gui.add(loadFromSubmit, "loadFromSubmit");

	loadFromSubmit->connect("pressed", &DrawFigures::LoadFromFile, &loadedData, loadFromFilename);
	
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Projekt - Dobrzanska, Kusarek, Augustyn", sf::Style::Titlebar | sf::Style::Close);
	tgui::Gui gui(window);
	DrawFigures loadedData;
	sf::RectangleShape borderBox(sf::Vector2f(200., 0.));
	borderBox.setOutlineColor(sf::Color::Black);
	borderBox.setFillColor(sf::Color::White);
	borderBox.setPosition(200., 0.);
	borderBox.setSize(sf::Vector2f(800., 600.));
	Gui::Panel newPanel(window, gui, loadedData);
	newPanel.preparePanel();
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
		newPanel.updatePanel();
		window.display();
	}


	return EXIT_SUCCESS;
}