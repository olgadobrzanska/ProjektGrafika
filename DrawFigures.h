#pragma once
#include <SFML/Graphics/Drawable.hpp>

/*! \mainpage Strona glowna
*
* \section intro_sec Wprowadzenie
*
* ##Projekt nr 34 z Podstaw Grafiki Komputerowej.
* 
* ### Wykonali:
* - Olga Dobrzanska
* - Dominika Kusarek
* - Pawel Augustyn
*
* \section libs Wykorzystane biblioteki
* 
* ### Biblioteki wykorzystane w projekcie:
* - SFML 2.4.2 32-bit (<a href="https://sfml-dev.org">Link</a>)
* - TGUI 0.7.4 32-bit (<a href="https://tgui.eu">Link</a>)
* - CImg 2.0.2 (<a href="http://cimg.eu">Link</a>)
*
*/

class DrawFigures : public sf::Drawable
{
public:
	DrawFigures();

	/**
	 * \brief Funkcja wczytujaca dane o figurach
	 * \param[in] file Zmienna przechowujaca nazwe wczytywanego pliku
	 * \return Prawda, gdy odczyt poprawny; Falsz, gdy niepoprawny
	 */
	bool LoadFromFile(tgui::EditBox::Ptr file);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~DrawFigures();

	//! Typy mozliwych do wyrysowania figur
	enum FigType
	{
		CIRCLE = 1, //!< Kolo
		RECTANGLE = 2, //!< Prostokat
		LINE = 3, //!< Linia
		POLYGON = 4, //!< Wielokat
		POLYGONCIRCLE = 5 //!< Wielokat foremny
	};

	/**
	 * \brief Liczba figur wczytanych z pliku
	 * \return Liczba figur
	 */
	int GetCountOfElements() const { return m_loadedFigures.size(); }

	/**
	 * \brief Typ rysowanej figury
	 * \param index Nr indeksu figury w kontenerze
	 * \return Typ figury (#FigType)
	 */
	int GetFigureType(const int& index) const;

	/**
	 *	\brief Skladowa R koloru obramowania figury
	 *	\param index Nr indeksu figury w konenterze
	 *	\return Skladowa R obramowania
	 *	\sa SetOutlineR
	 */
	int GetOutlineR(const int& index) const;

	/**
	*	\brief Ustawienie nowej wartosci skladowej R koloru obramowania
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*	\sa GetOutlineR
	*/
	void SetOutlineR(int value, const int& index);

	/**
	*	\brief Skladowa G koloru obramowania figury
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa G obramowania
	*	\sa SetOutlineG
	*/
	int GetOutlineG(const int& index) const;

	/**
	*	\brief Ustawienie nowej wartosci skladowej G koloru obramowania
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*	\sa GetOutlineG
	*/
	void SetOutlineG(int value, const int& index);

	/**
	*	\brief Skladowa B koloru obramowania figury
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa B obramowania
	*	\sa SetOutlineB
	*/
	int GetOutlineB(const int& index) const;

	/**
	*	\brief Ustawienie nowej wartosci skladowej B koloru obramowania
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*	\sa GetOutlineB
	*/
	void SetOutlineB(int value, const int& index);

	/**
	*	\brief Skladowa R koloru wypelnienia figury
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa R obramowania
	*	\sa SetInR
	*/
	int GetInR(const int& index) const;

	/**
	*	\brief Ustawienie nowej wartosci skladowej R koloru wypelnienia
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*	\sa GetInR
	*/
	void SetInR(int value, const int& index);

	/**
	*	\brief Skladowa G koloru wypelnienia figury
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa G obramowania
	*	\sa SetInG
	*/
	int GetInG(const int& index) const;

	/**
	*	\brief Ustawienie nowej wartosci skladowej G koloru wypelnienia
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*	\sa GetInG
	*/
	void SetInG(int value, const int& index);

	/**
	*	\brief Skladowa B koloru wypelnienia figury
	*	\param index Nr indeksu figury w konenterze
	*	\return Skladowa B obramowania
	*	\sa SetInB
	*/
	int GetInB(const int& index) const;

	/**
	*	\brief Ustawienie nowej wartosci skladowej B koloru wypelnienia
	*	\param value Nowa wartosc
	*	\param index Nr indeksu figury w konenterze
	*	\sa GetInB
	*/
	void SetInB(int value, const int& index);

	/**
	*	\brief Grubosc obramowania figury
	*	\param index Nr indeksu figury w konenterze
	*	\return Grubosc linii (w pikselach)
	*	\sa SetBorderSize
	*/
	int GetBorderSize(const int& index) const;

	/**
	 * \brief Ustawienie nowej grubosci obramowania figury
	 * 
	 * Dla figury typu LINE (#FigType), grubosc 0 oznacza pominiecie figury przy rysowaniu
	 * \param value Nowa wartosc
	 * \param index Nr indeksu figury w kontenerze
	 * \sa GetBorderSize
	 */
	void SetBorderSize(int value, const int& index);

	/**
	 * \brief Przezroczystosc figury
	 * \param index Nr indeksu figury w kontenerze
	 * \return Aktuana przezroczystosc figury
	 * \sa SetOpacity
	 */
	int GetOpacity(const int& index) const;

	/**
	 * \brief Ustawienie nowej przezroczystosci figury
	 * 
	 * Im wieksza wartosc, tym figura jest bardziej widoczna
	 * \param value Nowa wartosc (z przedzialu 0-255)
	 * \param index Nr indeksu figury w kontenerze
	 * \sa GetOpacity
	 */
	void SetOpacity(int value, const int& index);

	/**
	 * \brief Skladowa X-owa wspolrzednych wierzcholka
	 * \param index Nr indeksu figury w kontenerze
	 * \param pointNo Numer wierzcholka
	 * \return Aktualna wartosc skladowej X wierzcholka
	 * \sa SetPointX
	 */
	int GetPointX(const int& index, const int& pointNo) const;

	/**
	* \brief Ustawienie nowej wartosci wspolrzednej X wierzcholka
	* \param value Nowa wartosc
	* \param index Nr indeksu figury w kontenerze
	* \param pointNo Numer wierzcholka
	* \sa GetPointX
	*/
	void SetPointX(int value, const int& index, const int& pointNo);

	/**
	* \brief Skladowa Y-owa wspolrzednych wierzcholka
	* \param index Nr indeksu figury w kontenerze
	* \param pointNo Numer wierzcholka
	* \return Aktualna wartosc skladowej Y wierzcholka
	* \sa SetPointY
	*/
	int GetPointY(const int& index, const int& pointNo) const;

	/**
	* \brief Ustawienie nowej wartosci wspolrzednej Y wierzcholka
	* \param value Nowa wartosc
	* \param index Nr indeksu figury w kontenerze
	* \param pointNo Numer wierzcholka
	* \sa GetPointY
	*/
	void SetPointY(int value, const int& index, const int& pointNo);

	/**
	 * \brief Ilosc wierzcholkow uzytych do wyrysowania figury
	 * 
	 * Funkcja uzyteczna glownie przy rysowaniu figur typu POLYGON (#FigType)
	 * \param index Indeks figury w kontenerze m_loadedfigures_data
	 * \return Ilosc punktow
	 */
	int GetVertexCount(const int& index) const;

	/**
	 * \brief Ilosc wierzcholkow uzytych do wyrysowania figury
	 * 
	 * Funkcja uzyteczna glownie przy rysowaniu figur typu POLYGON (#FigType)
	 * \param data Wektor przechowujacy informacje o danej figurze
	 * \return Ilosc punktow
	 */
	static int GetVertexCount(const std::vector<int>& data) { return data[0] == LINE ? 2 : (data.size() - 9) / 2; }

	/**
	 * \brief Zamiana sasiadujacych warstw kolejnoscia miedzy soba
	 * \param[in] layerID ID przenoszonej warstwy
	 * \param[in] goRight Jesli prawda, zamieniamy z warstwa o ID wiekszym\n
	 * Jesli falsz, zamieniamy z wartswa o ID mniejszym
	 * \return Prawda, jesli zamiana poprawna\n 
	 * Falsz, jesli zamiana sie nie powiodla
	 */
	bool ChangeLayers(const int& layerID, bool goRight);

	/**
	 * \brief Kontroluje miganie przy zmianie aktualnie obslugiwanej figury
	 * \param figID ID figury ktora ma migac
	 */
	void blinkFigure(const int& figID) { m_blinkingFigure = figID; m_countdown_change_figure = 0; };

protected:
	/**
	 *	Wskazniki znajdujace sie w tym kontenerze to gotowe do wyrysowania figury 
	 *	skonstruowane na podstawie danych zawartych w polu m_loadedfigures_data \n
	 *	Wszystkie konstruowane obiekty dziedzicza po klasie Drawable, dlatego moga znajdowac 
	 *	sie w jednym kontenerze
	 */
	std::vector<sf::Drawable*> m_loadedFigures; //!< Figury gotowe do wyrysowania

	/**
	 *	Dane przechowywane w tym dwuwymiarowym wektorze sluza do generowania figur typu 
	 *	Drawable, ktore nastepnie rysowane sa w oknie glownym aplikacji.\n
	 *	Rozmiar glownego wektora okresla ilosc wczytanych figur, natomiast rozmiar 
	 *	wewnetrznych wektorow zalezy od typu figury (przechowywanej pod indeksem zerowym).\n\n
	 *	Format danych w poszczegolnych wektorach wyglada nastepujaco (typ podstawowy):\n
	 *	1 2 3 4 5 6 7 8 9 10 11 12 13
	 *	- 1: Typ figury
	 *	- (2-4): Kolor obramowania (skladowe R, G, B)
	 *	- (5-7): Kolor wypelnienia (skladowe R, G, B)
	 *	- 8: Grubosc obramowania figury (w pikselach)
	 *	- 9: Przezroczystosc figury \n 0 - calkowicie przezroczysta \n 255 - calkowicie nieprzezroczysta
	 *	- (10-11): Punkt poczatkowy figury (skladowe X, Y wierzcholka)
	 *	- (12-13): Punkt koncowy figury (skladowe X, Y wierzcholka)
	 *	
	 *	Wyszczegolnione specjalizacje
	 *	- Specjalizacja dla figury typu linia (#FigType LINE)\n
	 *	Brak przechowywania informacji o kolorze wypelnienia, pozostale indeksy zdekrementowane o 3 
	 *	(dlugosc wektora skrocona)
	 *	- Specjalizacja dla figury typu wielokat (#FigType POLYGON)\n
	 *	Dlugosc wektora zalezna od ilosci punktow, pola od 1 do 9 jak w typie podstawowym.\n
	 *	Pola od 10 dalej to informacje o kolejnych wierzcholkach wielokata.\n
	 *	Poprawna dlugosc wektora dla wielokata: 9 + 2*n, gdzie n - ilosc wierzcholkow
	 *	- Specjalizacja dla figury typu wielokat foremny(#FigType POLYGONCIRCLE)\n
	 *	Dlugosc wektora 13. Pola od 1 do 9 analogicznie jak w typie podstawowym.\n
	 *	Pola 10-11 opisuja wspolrzedne srodka wielokata foremnego\n
	 *	Pole 12 opisuje promien wielokata, pole 13 - ilosc wierzcholkow
	 */
	std::vector<std::vector<int> > m_loadedfigures_data; //!< Dane wyrysowywanych figur

private:
	static int m_xOffset; //!< X-owy Offset (uwzglednienie szerokosci GUI)
	static int m_yOffset; //!< Y-owy Offset (uwzglednienie obramowania pola do rysowania)

	mutable int m_countdown_change_figure;
	int m_blinkingFigure=-1;

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
	 * \return Wskaznik do gotowej do wyrysowania linii
	 */
	static sf::Drawable* m_addLine(std::vector<int>& data);

	/**
	* Utworzenie gotowego do rysowania kola
	* \param data Dane do utworzenia kola
	* \return Wskaznik do gotowego do wyrysowania kola
	*/
	static sf::Drawable* m_addCircle(std::vector<int>& data);

	/**
	* Utworzenie gotowego do rysowania prostokata
	* \param data Dane do utworzenia prostokata
	* \return Wskaznik do gotowego do wyrysowania prostokata
	*/
	static sf::Drawable* m_addRectangle(std::vector<int>& data);

	/**
	* Utworzenie gotowego do rysowania wielokata
	* \param data Dane do utworzenia wielokata
	* \return Wskaznik do gotowego do wyrysowania wielokata
	*/
	static sf::Drawable* m_addPolygon(std::vector<int>& data);

	/**
	 * Utworzenie gotowego do rysowania wielokata foremnego
	 * rysowanie odbywa sie poprzez wpisanie w okrag
	 * \param data Dane do utworzenia wielokata foremnego
	 * \return Wskaznik do gotowego do rysowania wielokata foremnego
	 */
	static sf::Drawable* m_addPolygonCircle(std::vector<int>& data);

	//! Wskaznik na funkcje do rysowania
	typedef sf::Drawable* (*drawingFunctionPointer)(std::vector<int>&);

	/**
	 * Zwrocenie wskaznika do funkcji odpowiedzialnej za rysowanie konkretnej figury
	 * \param figureType Typ rysowanej figury (#FigType)
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
