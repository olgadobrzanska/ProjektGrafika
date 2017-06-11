#pragma once

class DrawFigures : public sf::Drawable
{
public:
	DrawFigures();
	bool LoadFromFile(tgui::EditBox::Ptr file);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~DrawFigures();
	enum { CIRCLE = 1, RECTANGLE = 2, LINE = 3 };
private:
	std::vector<sf::Drawable*> m_loadedFigures;
	static int m_xOffset;
	static int m_yOffset;

	static bool m_isCorrectSizeOfVector(const std::vector<int>& data);

	static bool m_checkIfFileExists(const std::string& filename);
	static sf::Drawable* m_addLine(std::vector<int>& data);
	static sf::Drawable* m_addCircle(std::vector<int>& data);
	static sf::Drawable* m_addRectangle(std::vector<int>& data);
};
