#include "Main.h"
#include <fstream>

int DrawFigures::m_xOffset = 200;
int DrawFigures::m_yOffset = 5;

DrawFigures::DrawFigures()
{
	m_loadedFigures.clear();
}

DrawFigures::~DrawFigures()
{
	for (std::vector<sf::Drawable*>::iterator it = m_loadedFigures.begin(); it != m_loadedFigures.end(); ++it)
		delete *it;
}


void DrawFigures::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (std::vector<sf::Drawable*>::const_iterator it = m_loadedFigures.begin(); it != m_loadedFigures.end(); ++it)
		target.draw(**it);		
}

bool DrawFigures::LoadFromFile(DrawFigures* data, const std::string& filename)
{
	if (!m_checkIfFileExists(filename))
		return false;
	std::ifstream loadedFile(filename.c_str());

	data->m_loadedFigures.clear();

	sf::Drawable* addedFigure;

	char currentFigure;
	int startX, startY, endX, endY;
	int outR, outG, outB, inR, inG, inB;
	int borderSize, opacity;

	sf::Drawable* (*figure)(int, int, int, int, int, int, int, int, int, int, int, int);

	while (loadedFile >> currentFigure >> 
		startX >> startY >> endX >> endY >> 
		outR >> outG >> outB >> inR >> inG >> inB
		>> borderSize >> opacity)
	{
		switch(currentFigure)
		{
		case 'L':
			figure = m_addLine;
			break;
		case 'C':
			figure = m_addCircle;
			break;
		case 'R':
			figure = m_addRectangle;
			break;
		default:
			continue;
		}
		addedFigure = figure(startX, startY, endX, endY, outR, outG, outB, inR, inG, inB, borderSize, opacity);
		data->m_loadedFigures.push_back(addedFigure);
	}

	loadedFile.close();

	return true;
}

bool DrawFigures::m_checkIfFileExists(const std::string& filename)
{
	std::ifstream infile(filename.c_str());
	auto to_return = infile.good() ? true : false;
	infile.close();
	return to_return;
}

sf::Drawable* DrawFigures::m_addLine(int startX, int startY, int endX, int endY, int sR, int sG, int sB, int eR, int eG, int eB, int borderSize, int opacity)
{
	sf::RectangleShape* line = new sf::RectangleShape;
	line->setPosition((float)(m_xOffset + startX), (float)(m_yOffset + startY));
	line->setSize(sf::Vector2f((float)(endX - startX), 1.));
	line->setOutlineColor(sf::Color(sR, sG, sB, opacity));
	line->setFillColor(sf::Color(sR, sG, sB, opacity));
	line->setOutlineThickness((float)(borderSize-1));

	// TODO: Obliczanie rotacji na podstawie endX i endY
	//line->setRotation()


	Drawable* addedLine = line;
	return addedLine;
}

sf::Drawable* DrawFigures::m_addCircle(int startX, int startY, int endX, int endY, int sR, int sG, int sB, int eR, int eG, int eB, int borderSize, int opacity)
{
	sf::CircleShape* circle = new sf::CircleShape();
	circle->setOutlineColor(sf::Color(sR, sG, sB, opacity));
	circle->setFillColor(sf::Color(eR, eG, eB, opacity));
	circle->setRadius((float)(endX - startX));
	circle->setPosition((float)(m_xOffset+startX), (float)(m_yOffset+startY));
	circle->setOutlineThickness((float)borderSize);

	sf::Drawable* addedCircle = circle;
	return addedCircle;
}


sf::Drawable* DrawFigures::m_addRectangle(int startX, int startY, int endX, int endY, int sR, int sG, int sB, int eR, int eG, int eB, int borderSize, int opacity)
{
	sf::RectangleShape* rectangle = new sf::RectangleShape;
	rectangle->setPosition((float)(m_xOffset + startX), (float)(m_yOffset + startY));
	rectangle->setSize(sf::Vector2f((float)(endX - startX), (float)(endY - startY)));
	rectangle->setOutlineColor(sf::Color(sR, sG, sB, opacity));
	rectangle->setFillColor(sf::Color(sR, sG, sB, opacity));
	rectangle->setOutlineThickness((float)borderSize);

	Drawable* addedRectangle = rectangle;
	return addedRectangle;
}