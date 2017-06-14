#pragma once

class DrawFigures : public sf::Drawable
{
public:
	DrawFigures();

	/**
	 * Funkcja wczytujaca dane o figurach
	 * \param[in] file Zmienna przechowujaca nazwe wczytywanego pliku
	 * \return Prawda, gdy odczyt poprawny; Falsz, gdy niepoprawny
	 */
	bool LoadFromFile(tgui::EditBox::Ptr file);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~DrawFigures();

	//! \enum FigType Rozrysowanie mozliwych do wyrysowania figur
	enum FigType
	{
		CIRCLE = 1, //!< Kolo
		RECTANGLE = 2, //!< Prostokat
		LINE = 3, //!< Linia
		POLYGON = 4 //!< Wielokat
	};

	/**
	 * Funkcja zwracajaca liczbe figur wczytanych z pliku
	 * \return Liczba figur
	 */
	int GetCountOfElements() const { return m_loadedFigures.size(); }

	/**
	 * Funkcja zwracajaca informacje o typie rysowanej figury
	 * \param index Nr indeksu figury w kontenerze
	 * \return Typ figury (enum FigType)
	 */
	int GetFigureType(const int& index) const;

	/**
	 *	Funkcja zwracajaca skladowa R koloru linii
	 *	\param index Nr indeksu figury w konenterze
	 *	\return Skladowa R obramowania
	 */
	int GetOutlineR(const int& index) const;

	/**
	*	Funkcja ustawiajaca nowa wartosc skladowej R koloru linii
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*/
	void SetOutlineR(int value, const int& index);

	/**
	*	Funkcja zwracajaca skladowa G koloru linii
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa G obramowania
	*/
	int GetOutlineG(const int& index) const;

	/**
	*	Funkcja ustawiajaca nowa wartosc skladowej G koloru linii
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*/
	void SetOutlineG(int value, const int& index);

	/**
	*	Funkcja zwracajaca skladowa B koloru linii
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa B obramowania
	*/
	int GetOutlineB(const int& index) const;

	/**
	*	Funkcja ustawiajaca nowa wartosc skladowej B koloru linii
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*/
	void SetOutlineB(int value, const int& index);

	/**
	*	Funkcja zwracajaca skladowa R koloru wypelnienia
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa R obramowania
	*/
	int GetInR(const int& index) const;

	/**
	*	Funkcja ustawiajaca nowa wartosc skladowej R koloru wypelnienia
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*/
	void SetInR(int value, const int& index);

	/**
	*	Funkcja zwracajaca skladowa G koloru wypelnienia
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa G obramowania
	*/
	int GetInG(const int& index) const;

	/**
	*	Funkcja ustawiajaca nowa wartosc skladowej G koloru wypelnienia
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*/
	void SetInG(int value, const int& index);

	/**
	*	Funkcja zwracajaca skladowa B koloru wypelnienia
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa B obramowania
	*/
	int GetInB(const int& index) const;

	/**
	*	Funkcja ustawiajaca nowa wartosc skladowej B koloru wypelnienia
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*/
	void SetInB(int value, const int& index);

	/**
	*	Funkcja zwracajaca grubosc obrysu figury
	*	\param index Nr indeksu figury w konenterze
	*	\return Grubosc linii (w pikselach)
	*/
	int GetBorderSize(const int& index) const;

	/**
	 * Funkcja ustawiajaca nowa grubosc obrysu figury
	 * \param value Nowa wartosc
	 * \param index Nr indeksu figury w kontenerze
	 */
	void SetBorderSize(int value, const int& index);

	/**
	 * Funkcja zwracajaca aktualna przezroczystosc figury
	 * \param index Nr indeksu figury w kontenerze
	 * \return Aktuana przezroczystosc figury
	 */
	int GetOpacity(const int& index) const;

	/**
	 * Ustawienie nowej wartosci przezroczystoci dla figury
	 * \param value Nowa wartosc (z przedzialu 0-255)
	 * \param index Nr indeksu figury w kontenerze
	 */
	void SetOpacity(int value, const int& index);

	/**
	 * Pobranie skladowej X wierzcholka
	 * \param index Nr indeksu figury w kontenerze
	 * \param pointNo Numer wierzcholka
	 * \return Aktualna wartosc skladowej X wierzcholka
	 */
	int GetPointX(const int& index, const int& pointNo) const;

	/**
	* Ustawienie nowej wartosci skladowej X wierzcholka
	* \param value Nowa wartosc
	* \param index Nr indeksu figury w kontenerze
	* \param pointNo Numer wierzcholka
	*/
	void SetPointX(int value, const int& index, const int& pointNo);

	/**
	* Pobranie skladowej Y wierzcholka
	* \param index Nr indeksu figury w kontenerze
	* \param pointNo Numer wierzcholka
	* \return Aktualna wartosc skladowej Y wierzcholka
	*/
	int GetPointY(const int& index, const int& pointNo) const;

	/**
	* Ustawienie nowej wartosci skladowej Y wierzcholka
	* \param value Nowa wartosc
	* \param index Nr indeksu figury w kontenerze
	* \param pointNo Numer wierzcholka
	*/
	void SetPointY(int value, const int& index, const int& pointNo);

	/**
	 * Funkcja liczaca ilosc punktow dla danej figury, ktore potrzebne sa do wyrysowania figury
	 * \param index Indeks figury w kontenerze m_loadedfigures_data
	 * \return Ilosc punktow
	 */
	int GetVertexCount(const int& index) const;

	/**
	 * Funkcja liczaca ilosc punktow dla danej figury, ktore potrzebne sa do wyrysowania figury
	 * \param data Wektor przechowujacy informacje o danej figurze
	 * \return Ilosc punktow
	 */
	static int GetVertexCount(const std::vector<int>& data) { return data[0] == LINE ? 2 : (data.size() - 9) / 2; }
private:
	std::vector<sf::Drawable*> m_loadedFigures; //!< Figury gotowe do wyrysowania
	std::vector<std::vector<int> > m_loadedfigures_data; //!< Dane wyrysowywanych figur
	static int m_xOffset; //!< X-owy Offset (uwzglednienie szerokosci GUI)
	static int m_yOffset; //!< Y-owy Offset (uwzglednienie obramowania pola do rysowania)

	/**
	 * Funkcja sprawdzajaca poprawnosc danych we wczytywanym pliku dla poszczegolnych figur
	 * \param data Wczytana figura
	 * \return Prawda, gdy dane sa poprawne; Falsz - w przeciwnym wypadku
	 */
	static bool m_isCorrectSizeOfVector(const std::vector<int>& data);

	/**
	 * Sprawdzenie czy plik o zadanej nazwie istnieje
	 * \param filename Nazwa pliku
	 * \return Prawda, gdy plik istnieje
	 */
	static bool m_checkIfFileExists(const std::string& filename);
	
	/**
	 * Utworzenie gotowej do rysowania linii
	 * \param data Dane do utworzenia linii
	 * \return Gotowa do wyrysowania linia
	 */
	static sf::Drawable* m_addLine(std::vector<int>& data);

	/**
	* Utworzenie gotowego do rysowania kola
	* \param data Dane do utworzenia kola
	* \return Gotowe do wyrysowania kolo
	*/
	static sf::Drawable* m_addCircle(std::vector<int>& data);

	/**
	* Utworzenie gotowego do rysowania prostokata
	* \param data Dane do utworzenia prostokata
	* \return Gotowe do wyrysowania prostokata
	*/
	static sf::Drawable* m_addRectangle(std::vector<int>& data);

	/**
	* Utworzenie gotowego do rysowania wielokata
	* \param data Dane do utworzenia wielokata
	* \return Gotowe do wyrysowania wielokata
	*/
	static sf::Drawable* m_addPolygon(std::vector<int>& data);

	//! Wskaznik na funkcje do rysowania
	typedef sf::Drawable* (*drawingFunctionPointer)(std::vector<int>&);

	/**
	 * Zwrocenie wskaznika do funkcji odpowiedzialnej za rysowanie konkretnej figury
	 * \param figureType Typ rysowanej figury (enum FigType)
	 * \return Wskaznik do rysujacej funkcji 
	 */
	static drawingFunctionPointer m_getDrawingFunction(int figureType);

	/**
	 * Uaktualnienie kontenera z gotowymi do rysowania figurami
	 * \param index Numer indeksu uaktualnianej figury
	 */
	void m_updateDrawableTable(const int& index);

	/**
	 * Walidacja dla kolorow oraz przezroczystoci
	 * \param val Sprawdzana wartosc
	 * \return Zwalidowana wartosc
	 */
	static int m_proper_value_0_255(const int& val) { return (val > 255) ? 255 : ((val < 0) ? 0 : val); }
};
