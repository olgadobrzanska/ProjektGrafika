#include "Main.h"


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Projekt - Dobrzanska, Kusarek, Augustyn", sf::Style::Titlebar | sf::Style::Close, settings);
	tgui::Gui gui(window);
	window.setFramerateLimit(30);
	DrawFigures loadedData;
	sf::RectangleShape borderBox(sf::Vector2f(200., 0.));
	borderBox.setOutlineColor(sf::Color::Black);
	borderBox.setFillColor(sf::Color::White);
	borderBox.setPosition(200., 0.);
	borderBox.setSize(sf::Vector2f(800., 600.));
	sf::RectangleShape guiBackground;
	guiBackground.setFillColor(sf::Color::Black);
	guiBackground.setPosition(0., 0.);
	guiBackground.setSize(sf::Vector2f(200., 600.));


	try
	{
		Gui::Panel newPanel(window, gui, loadedData);
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
			window.draw(guiBackground);
			gui.draw();
			newPanel.updatePanel();
			window.display();
		}
	}
	catch (const tgui::Exception&)
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

			}

			window.clear();
			window.display();
		}
	}



	return EXIT_SUCCESS;
}