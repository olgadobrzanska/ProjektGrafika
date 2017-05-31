#pragma once

class DrawFigures : public sf::Drawable
{
public:
	DrawFigures();
	static bool LoadFromFile(DrawFigures* data, const std::string& filename);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~DrawFigures();
private:
	std::vector<sf::Drawable*> m_loadedFigures;
	static int m_xOffset;
	static int m_yOffset;

	static bool m_checkIfFileExists(const std::string& filename);
	static sf::Drawable* m_addLine(int startX, int startY, int endX, int endY, 
		int sR, int sG, int sB, int eR, int eG, int eB, int borderSize, int opacity);
	static sf::Drawable* m_addCircle(int startX, int startY, int endX, int endY,
		int sR, int sG, int sB, int eR, int eG, int eB, int borderSize, int opacity);
	static sf::Drawable* m_addRectangle(int startX, int startY, int endX, int endY,
		int sR, int sG, int sB, int eR, int eG, int eB, int borderSize, int opacity);
};
