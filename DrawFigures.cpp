#include "Main.h"
#include <fstream>

int DrawFigures::m_xOffset = 200;
int DrawFigures::m_yOffset = 5;

DrawFigures::DrawFigures()
{
	m_loadedFigures.clear();
	m_loadedfigures_data.clear();
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

int DrawFigures::GetOutlineR(const int& index) const 
{
	return m_loadedfigures_data[index][1];
}

void DrawFigures::SetOutlineR(int value, const int& index)
{
	m_loadedfigures_data[index][1] = value;
	sf::Color color(m_loadedfigures_data[index][1], m_loadedfigures_data[index][2], m_loadedfigures_data[index][3]);

}

int DrawFigures::GetOutlineG(const int& index) const
{
	return m_loadedfigures_data[index][2];
}

void DrawFigures::SetOutlineG(int value, const int& index)
{
	
}


int DrawFigures::GetOutlineB(const int& index) const
{
	return m_loadedfigures_data[index][3];
}

void DrawFigures::SetOutlineB(int value, const int& index)
{
	
}

int DrawFigures::GetInR(const int& index) const
{
	return m_loadedfigures_data[index][4];
}

void DrawFigures::SetInR(int value, const int& index)
{
	
}

int DrawFigures::GetInG(const int& index) const
{
	return m_loadedfigures_data[index][5];
}

void DrawFigures::SetInG(int value, const int& index)
{
	
}

int DrawFigures::GetInB(const int& index) const
{
	return m_loadedfigures_data[index][6];
}

void DrawFigures::SetInB(int value, const int& index)
{
	
}

int DrawFigures::GetBorderSize(const int& index) const  
{
	return m_loadedfigures_data[index][7];
}

void DrawFigures::SetBorderSize(int value, const int& index)
{
	
}

int DrawFigures::GetOpacity(const int& index) const 
{
	return m_loadedfigures_data[index][8];
}

void DrawFigures::SetOpacity(int value, const int& index)
{
	
}

int DrawFigures::GetPointX(const int& index, const int& pointNo) const
{
	return m_loadedfigures_data[index][9 + pointNo * 2];
}

void DrawFigures::SetPointX(int value, const int& index)
{
	
}

int DrawFigures::GetPointY(const int& index, const int& pointNo) const
{
	return m_loadedfigures_data[index][10 + pointNo * 2];
}

void DrawFigures::SetPointY(int value, const int& index)
{
	
}

bool DrawFigures::LoadFromFile(tgui::EditBox::Ptr file)
{
	std::string filename = file->getText().toAnsiString();
	if (!m_checkIfFileExists(filename))
		return false;
	std::ifstream loadedFile(filename.c_str());

	this->m_loadedFigures.clear();

	sf::Drawable* addedFigure;

	std::string s;

	while (std::getline(loadedFile, s))
	{
		std::istringstream iss(s);
		std::vector<int> data;
		std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::inserter(data, data.begin()));

		if (!m_isCorrectSizeOfVector(data))
			continue;

		switch (data[0])
		{
		case CIRCLE:
			addedFigure = m_addCircle(data);
			break;
		case RECTANGLE:
			addedFigure = m_addRectangle(data);
			break;
		case LINE:
			addedFigure = m_addLine(data);
			break;
		default:
			continue;
		}

		this->m_loadedFigures.push_back(addedFigure);
		this->m_loadedfigures_data.push_back(data);
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

bool DrawFigures::m_isCorrectSizeOfVector(const std::vector<int>& data)
{
	if (data.size() == 0)
		return false;
	int expectedSize = -1;
	switch (data[0])
	{
	case CIRCLE:
		expectedSize = 13;
		break;
	case RECTANGLE:
		expectedSize = 13;
		break;
	case LINE:
		expectedSize = 10;
		break;
	}
	return expectedSize == data.size();
}


sf::Drawable* DrawFigures::m_addLine(std::vector<int>& data)
{
	int colorR = data[1], colorG = data[2], colorB = data[3];
	int borderSize = data[4], opacity = data[5];
	int startX = data[6], startY = data[7], endX = data[8], endY = data[9];
	sf::RectangleShape* line = new sf::RectangleShape;
	line->setPosition((float)(m_xOffset + startX), (float)(m_yOffset + startY));
	line->setSize(sf::Vector2f((float)(endX - startX), 1.));
	line->setOutlineColor(sf::Color(colorR, colorG, colorB, opacity));
	line->setFillColor(sf::Color(colorR, colorG, colorB, opacity));
	line->setOutlineThickness((float)(borderSize-1));

	// TODO: Obliczanie rotacji na podstawie endX i endY
	//line->setRotation()


	Drawable* addedLine = line;
	return addedLine;
}

sf::Drawable* DrawFigures::m_addCircle(std::vector<int>& data)
{
	int colorR = data[1], colorG = data[2], colorB = data[3];
	int insideR = data[4], insideG = data[5], insideB = data[6];
	int borderSize = data[7], opacity = data[8];
	int startX = data[9], startY = data[10], endX = data[11], endY = data[12];
	sf::CircleShape* circle = new sf::CircleShape();
	circle->setOutlineColor(sf::Color(colorR, colorG, colorB, opacity));
	circle->setFillColor(sf::Color(insideR, insideG, insideB, opacity));
	circle->setRadius((float)(endX - startX));
	circle->setPosition((float)(m_xOffset+startX), (float)(m_yOffset+startY));
	circle->setOutlineThickness((float)borderSize);

	sf::Drawable* addedCircle = circle;
	return addedCircle;
}


sf::Drawable* DrawFigures::m_addRectangle(std::vector<int>& data)
{
	int colorR = data[1], colorG = data[2], colorB = data[3];
	int insideR = data[4], insideG = data[5], insideB = data[6];
	int borderSize = data[7], opacity = data[8];
	int startX = data[9], startY = data[10], endX = data[11], endY = data[12];
	sf::RectangleShape* rectangle = new sf::RectangleShape;
	rectangle->setPosition((float)(m_xOffset + startX), (float)(m_yOffset + startY));
	rectangle->setSize(sf::Vector2f((float)(endX - startX), (float)(endY - startY)));
	rectangle->setOutlineColor(sf::Color(colorR, colorG, colorB, opacity));
	rectangle->setFillColor(sf::Color(insideR, insideG, insideB, opacity));
	rectangle->setOutlineThickness((float)borderSize);

	Drawable* addedRectangle = rectangle;
	return addedRectangle;
}