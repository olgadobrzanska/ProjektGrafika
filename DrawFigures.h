#pragma once

class DrawFigures : public sf::Drawable
{
public:
	DrawFigures();
	bool LoadFromFile(tgui::EditBox::Ptr file);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~DrawFigures();
	enum { CIRCLE = 1, RECTANGLE = 2, LINE = 3 };
	int GetCountOfElements() const { return m_loadedFigures.size(); }
	int GetOutlineR(const int& index) const;
	int GetOutlineG(const int& index) const;
	int GetOutlineB(const int& index) const;
	int GetInR(const int& index) const;
	int GetInG(const int& index) const;
	int GetInB(const int& index) const;
	int GetBorderSize(const int& index) const;
	int GetOpacity(const int& index) const;
	int GetPointX(const int& index, const int& pointNo) const;
	int GetPointY(const int& index, const int& pointNo) const;
private:
	std::vector<sf::Drawable*> m_loadedFigures;
	std::vector<std::vector<int> > m_loadedfigures_data;
	static int m_xOffset;
	static int m_yOffset;

	static bool m_isCorrectSizeOfVector(const std::vector<int>& data);

	static bool m_checkIfFileExists(const std::string& filename);
	static sf::Drawable* m_addLine(std::vector<int>& data);
	static sf::Drawable* m_addCircle(std::vector<int>& data);
	static sf::Drawable* m_addRectangle(std::vector<int>& data);
};
