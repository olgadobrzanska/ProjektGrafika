#pragma once

typedef sf::Drawable* (*drawingFunctionPointer)(std::vector<int>&);

class DrawFigures : public sf::Drawable
{
public:
	DrawFigures();
	bool LoadFromFile(tgui::EditBox::Ptr file);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~DrawFigures();
	enum
	{
		CIRCLE = 1, 
		RECTANGLE = 2, 
		LINE = 3, 
		POLYGON = 4
	};
	int GetCountOfElements() const { return m_loadedFigures.size(); }
	int GetFigureType(const int& index) const;
	int GetOutlineR(const int& index) const;
	void SetOutlineR(int value, const int& index);
	int GetOutlineG(const int& index) const;
	void SetOutlineG(int value, const int& index);
	int GetOutlineB(const int& index) const;
	void SetOutlineB(int value, const int& index);
	int GetInR(const int& index) const;
	void SetInR(int value, const int& index);
	int GetInG(const int& index) const;
	void SetInG(int value, const int& index);
	int GetInB(const int& index) const;
	void SetInB(int value, const int& index);
	int GetBorderSize(const int& index) const;
	void SetBorderSize(int value, const int& index);
	int GetOpacity(const int& index) const;
	void SetOpacity(int value, const int& index);
	int GetPointX(const int& index, const int& pointNo) const;
	void SetPointX(int value, const int& index, const int& pointNo);
	int GetPointY(const int& index, const int& pointNo) const;
	void SetPointY(int value, const int& index, const int& pointNo);
	int GetVertexCount(const int& index) const;
	static int GetVertexCount(const std::vector<int>& data) { return data[0] == LINE ? 2 : (data.size() - 9) / 2; }
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
	static sf::Drawable* m_addPolygon(std::vector<int>& data);
	static drawingFunctionPointer m_getDrawingFunction(int figureType);
	void m_updateDrawableTable(const int& index);
	static int m_proper_value_0_255(const int& val) { return (val > 255) ? 255 : ((val < 0) ? 0 : val); }
};
