#include "Main.h"
#include <fstream>

int DrawFigures::m_xOffset = 202;
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

int DrawFigures::GetFigureType(const int& index) const
{
	return m_loadedfigures_data[index][0];
}

int DrawFigures::GetOutlineR(const int& index) const
{
	return m_loadedfigures_data[index][1];
}

void DrawFigures::SetOutlineR(int value, const int& index)
{
	m_loadedfigures_data[index][1] = m_proper_value_0_255(value);
	m_updateDrawableTable(index);
}

int DrawFigures::GetOutlineG(const int& index) const
{
	return m_loadedfigures_data[index][2];
}

void DrawFigures::SetOutlineG(int value, const int& index)
{
	m_loadedfigures_data[index][2] = m_proper_value_0_255(value);
	m_updateDrawableTable(index);
}


int DrawFigures::GetOutlineB(const int& index) const
{
	return m_loadedfigures_data[index][3];
}

void DrawFigures::SetOutlineB(int value, const int& index)
{
	m_loadedfigures_data[index][3] = m_proper_value_0_255(value);
	m_updateDrawableTable(index);
}

int DrawFigures::GetInR(const int& index) const
{
	return m_loadedfigures_data[index][4];
}

void DrawFigures::SetInR(int value, const int& index)
{
	m_loadedfigures_data[index][4] = m_proper_value_0_255(value);
	m_updateDrawableTable(index);
}

int DrawFigures::GetInG(const int& index) const
{
	return m_loadedfigures_data[index][5];
}

void DrawFigures::SetInG(int value, const int& index)
{
	m_loadedfigures_data[index][5] = m_proper_value_0_255(value);
	m_updateDrawableTable(index);
}

int DrawFigures::GetInB(const int& index) const
{
	return m_loadedfigures_data[index][6];
}

void DrawFigures::SetInB(int value, const int& index)
{
	m_loadedfigures_data[index][6] = m_proper_value_0_255(value);
	m_updateDrawableTable(index);
}

int DrawFigures::GetBorderSize(const int& index) const
{
	int borderIndex = 7;
	if (m_loadedfigures_data[index][0] == LINE)
		borderIndex -= 3;
	return m_loadedfigures_data[index][borderIndex];
}

void DrawFigures::SetBorderSize(int value, const int& index)
{
	int borderIndex = 7;
	if (m_loadedfigures_data[index][0] == LINE)
		borderIndex -= 3;
	if (value < 0) value = 0;
	m_loadedfigures_data[index][borderIndex] = value;
	m_updateDrawableTable(index);
}

int DrawFigures::GetOpacity(const int& index) const
{
	int opacityIndex = 8;
	if (m_loadedfigures_data[index][0] == LINE)
		opacityIndex -= 3;
	return m_loadedfigures_data[index][opacityIndex];
}

void DrawFigures::SetOpacity(int value, const int& index)
{
	int opacityIndex = 8;
	if (m_loadedfigures_data[index][0] == LINE)
		opacityIndex -= 3;
	m_loadedfigures_data[index][opacityIndex] = m_proper_value_0_255(value);
	m_updateDrawableTable(index);
}

int DrawFigures::GetPointX(const int& index, const int& pointNo) const
{
	int xIndex = 9;
	if (m_loadedfigures_data[index][0] == LINE)
		xIndex -= 3;
	return m_loadedfigures_data[index][xIndex + pointNo * 2];
}

void DrawFigures::SetPointX(int value, const int& index, const int& pointNo)
{
	if (pointNo > GetVertexCount(index) - 1 || pointNo < 0)
		return;
	int xIndex = 9;
	if (m_loadedfigures_data[index][0] == LINE)
		xIndex -= 3;
	m_loadedfigures_data[index][xIndex + pointNo * 2] = value;
	m_updateDrawableTable(index);
}

int DrawFigures::GetPointY(const int& index, const int& pointNo) const
{
	int yIndex = 10;
	if (m_loadedfigures_data[index][0] == LINE)
		yIndex -= 3;
	return m_loadedfigures_data[index][yIndex + pointNo * 2];
}

void DrawFigures::SetPointY(int value, const int& index, const int& pointNo)
{
	if (pointNo > GetVertexCount(index) - 1 || pointNo < 0)
		return;
	int yIndex = 10;
	if (m_loadedfigures_data[index][0] == LINE)
		yIndex -= 3;
	m_loadedfigures_data[index][yIndex + pointNo * 2] = value;
	m_updateDrawableTable(index);
}

int DrawFigures::GetVertexCount(const int& index) const
{
	if (m_loadedfigures_data[index][0] == LINE)
		return 2;
	return (m_loadedfigures_data[index].size() - 9) / 2;
}

bool DrawFigures::ChangeLayers(const int& layerID, bool goRight)
{
	if (layerID < 0 || layerID > GetCountOfElements() - 1)
		return false;
	if (layerID == 0 && !goRight)
		return false;
	if (layerID == GetCountOfElements() - 1 && goRight)
		return false;
	int secondIndex = (goRight) ? layerID + 1 : layerID - 1;
	std::swap(m_loadedfigures_data[layerID], m_loadedfigures_data[secondIndex]);
	std::swap(m_loadedFigures[layerID], m_loadedFigures[secondIndex]);
	return true;
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

		this->m_loadedfigures_data.push_back(data);

		addedFigure = m_getDrawingFunction(data[0])(data);

		this->m_loadedFigures.push_back(addedFigure);
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
	case POLYGON:
		return data.size()-13 >= 0 && (data.size() - 13) % 2 == 0;
	case POLYGONCIRCLE:
		expectedSize = 13;
	}
	return expectedSize == data.size();
}


sf::Drawable* DrawFigures::m_addLine(std::vector<int>& data)
{
	int colorR = m_proper_value_0_255(data[1]), colorG = m_proper_value_0_255(data[2]), colorB = m_proper_value_0_255(data[3]);
	int borderSize = data[4], opacity = m_proper_value_0_255(data[5]);
	if (borderSize == 0)
		opacity = 0;
	int startX = data[6], startY = data[7], endX = data[8], endY = data[9];
	if (endX < startX)
	{
		std::swap(endX, startX);
		std::swap(endY, startY);
	}
	sf::RectangleShape* line = new sf::RectangleShape;
	line->setPosition((float)(m_xOffset + startX), (float)(m_yOffset + startY));
	line->setSize(sf::Vector2f((float)(std::sqrt((endX - startX)*(endX-startX)+(endY-startY)*(endY-startY))), 1.));
	line->setOutlineColor(sf::Color(colorR, colorG, colorB, opacity));
	line->setFillColor(sf::Color(colorR, colorG, colorB, opacity));
	line->setOutlineThickness((float)(borderSize-1));

	if (endX - startX == 0)
		line->setRotation(90);
	else
		line->setRotation((float)(atan(1.*(endY - startY) / (endX - startX)) * 180. / M_PI));




	Drawable* addedLine = line;
	return addedLine;
}

sf::Drawable* DrawFigures::m_addCircle(std::vector<int>& data)
{
	int colorR = m_proper_value_0_255(data[1]), colorG = m_proper_value_0_255(data[2]), colorB = m_proper_value_0_255(data[3]);
	int insideR = m_proper_value_0_255(data[4]), insideG = m_proper_value_0_255(data[5]), insideB = m_proper_value_0_255(data[6]);
	int borderSize = data[7], opacity = m_proper_value_0_255(data[8]);
	int startX = data[9], startY = data[10], endX = data[11], endY = data[12];
	sf::CircleShape* circle = new sf::CircleShape();
	circle->setOutlineColor(sf::Color(colorR, colorG, colorB, opacity));
	circle->setFillColor(sf::Color(insideR, insideG, insideB, opacity));
	circle->setRadius((float)std::sqrt((endX - startX)*(endX - startX) + (endY - startY)*(endY - startY)));
	circle->setPosition((float)(m_xOffset+startX-circle->getRadius()), (float)(m_yOffset+startY-circle->getRadius()));
	circle->setOutlineThickness((float)borderSize);

	sf::Drawable* addedCircle = circle;
	return addedCircle;
}


sf::Drawable* DrawFigures::m_addRectangle(std::vector<int>& data)
{
	int colorR = m_proper_value_0_255(data[1]), colorG = m_proper_value_0_255(data[2]), colorB = m_proper_value_0_255(data[3]);
	int insideR = m_proper_value_0_255(data[4]), insideG = m_proper_value_0_255(data[5]), insideB = m_proper_value_0_255(data[6]);
	int borderSize = data[7], opacity = m_proper_value_0_255(data[8]);
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

sf::Drawable* DrawFigures::m_addPolygon(std::vector<int>& data)
{
	int pointCount = GetVertexCount(data);
	sf::ConvexShape* polygon = new sf::ConvexShape(pointCount);
	int colorR = m_proper_value_0_255(data[1]), colorG = m_proper_value_0_255(data[2]), colorB = m_proper_value_0_255(data[3]);
	int insideR = m_proper_value_0_255(data[4]), insideG = m_proper_value_0_255(data[5]), insideB = m_proper_value_0_255(data[6]);
	int borderSize = data[7], opacity = m_proper_value_0_255(data[8]);
	
	for (int i = 0; i < pointCount; i++)
	{
		const sf::Vector2f point((float)(data[9 + 2 * i]-data[9]), (float)(data[10 + 2 * i]-data[10]));
		polygon->setPoint(i, point);
	}
	polygon->setOutlineColor(sf::Color(colorR, colorG, colorB, opacity));
	polygon->setFillColor(sf::Color(insideR, insideG, insideB, opacity));
	polygon->setOutlineThickness((float)borderSize);
	polygon->setPosition((float)(m_xOffset + data[9]), (float)(m_yOffset + data[10]));

	sf::Drawable* addedPolygon = polygon;
	return addedPolygon;
}

sf::Drawable* DrawFigures::m_addPolygonCircle(std::vector<int>& data)
{
	int pointCount = data[12];
	int colorR = m_proper_value_0_255(data[1]), colorG = m_proper_value_0_255(data[2]), colorB = m_proper_value_0_255(data[3]);
	int insideR = m_proper_value_0_255(data[4]), insideG = m_proper_value_0_255(data[5]), insideB = m_proper_value_0_255(data[6]);
	int borderSize = data[7], opacity = m_proper_value_0_255(data[8]);
	sf::CircleShape *shape = new sf::CircleShape((float)data[11], pointCount);
	shape->setOutlineColor(sf::Color(colorR, colorG, colorB, opacity));
	shape->setFillColor(sf::Color(insideR, insideG, insideB, opacity));
	shape->setOutlineThickness(float(borderSize));
	shape->setPosition((float)(m_xOffset + data[9]), (float)(m_yOffset + data[10]));

	sf::Drawable* addedPolygon = shape;
	return addedPolygon;
}


DrawFigures::drawingFunctionPointer DrawFigures::m_getDrawingFunction(int figureType)
{
	drawingFunctionPointer fp;
	switch (figureType)
	{
	case CIRCLE:
		fp = m_addCircle;
		break;
	case RECTANGLE:
		fp = m_addRectangle;
		break;
	case LINE:
		fp = m_addLine;
		break;
	case POLYGON:
		fp = m_addPolygon;
		break;
	case POLYGONCIRCLE:
		fp = m_addPolygonCircle;
		break;
	default:
		fp = m_addCircle;
	}
	return fp;
}

void DrawFigures::m_updateDrawableTable(const int& index)
{
	sf::Drawable* newItem = m_getDrawingFunction(m_loadedfigures_data[index][0])(m_loadedfigures_data[index]);
	std::swap(newItem, m_loadedFigures[index]);
	delete newItem;
}
