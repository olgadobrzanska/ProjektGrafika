#include "Main.h"


void loadGui(tgui::Gui& gui, DrawFigures* loadedData)
{
	//tgui::Theme::Ptr theme = tgui::Theme::create("../../widgets/Black.txt");
	tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt");
	
	tgui::EditBox::Ptr loadFromFilename = theme->load("Editbox");
	loadFromFilename->setSize(140, 50);
	loadFromFilename->setPosition(5, 5);
	loadFromFilename->setText("data.txt");
	gui.add(loadFromFilename, "loadFromFilename");

	tgui::Button::Ptr loadFromSubmit = theme->load("Button");
	loadFromSubmit->setSize(40, 50);
	loadFromSubmit->setText("Load");
	loadFromSubmit->setPosition(155, 5);
	gui.add(loadFromSubmit, "loadFromSubmit");

	loadFromSubmit->connect("pressed", DrawFigures::LoadFromFile, loadedData, loadFromFilename->getText().toAnsiString());

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	tgui::Gui gui(window);
	DrawFigures* loadedData = new DrawFigures();
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

		window.clear(sf::Color::White);
		window.draw(*loadedData);
		gui.draw();
		window.display();
	}

	delete loadedData;

	return EXIT_SUCCESS;
}