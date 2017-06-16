#pragma once
#include "DrawFigures.h"
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

namespace Gui
{
	class Panel {
	public:

		/**
		* Konstruktor klasy Panel
		* \param[in] zmienna przechowywujaca /... uzupelnic/
		* \param[in] zmienna przechowywujaca parametry wszystkich figur
		*/
		Panel(sf::RenderWindow& window, tgui::Gui& gui, DrawFigures& loadedData);
		
		/**
		* Metoda przygotywujaca interfejs uzytkownika 
		*/
		void preparePanel();

		/**
		* Metoda dostosowuje interfejs po wczytaniu pliku
		*/
		void updatePanel();

		/**
		* Metoda obslugujaca przycisk "lewej strzalki" - zmienia na kolejna figure do modyfikacji
		*/
		void leftArrowPressed();

		/**
		* Metoda obslugujaca przycisk "prawej strzalki" - zmienia na poprzednia figure do modyfikacji
		*/
		void rightArrowPressed();
		
		/**
		* Metoda obslugujaca przycisk "gornej strzalki" - przesuwa aktualn¹ warstwe o jeden poziom wyzej
		*/
		void upArrowVertexPressed();

		/**
		* Metoda obslugujaca przycisk "dolnej strzalki" - przesuwa aktualn¹ warstwe o jeden poziom nizej
		*/
		void downArrowVertexPressed();

		/**
		* Metoda wypisuje na ekran rodzaj aktualnej figury
		*/
		void updateFigureName();

		/**
		* Metoda wypisuje na ekran aktualny kolor linii zewnetrznej figury
		*/
		void updateLineColorInfo();

		/**
		* Metoda wypisuje na ekran aktualny kolor wypelnienia figury
		*/
		void updateFulfilColorInfo();

		/**
		* Metoda wypisuje na ekran aktualna grubosc linii figury
		*/
		void updateBorderSize();

		/**
		* Metoda wypisuje na ekran aktualna przezrocystosc figury
		*/
		void updateOpacity();

		/**
		* Metoda wypisuje na ekran wspolrzedne aktualnej figury
		*/
		void updateVertexes();

		/**
		* Metoda sprawdza jaki jest wybor uzytkownika z comboboxu i wypisuje ponizej (w tekst box) sposob podania nowych danych
		*/
		void checkParameterToChange();

		/**
		* Metoda pobiera z tekstboxu nowe parametry, podane przez uzytkowika i uaktualnia je na rysunku
		*/
		void refreshButtonPressed();

		/**
		* Metoda obslugujaca przycisk "gornej strzalki" - umozliwia odczyt polozenia wszystkich wierzcholkow figury
		*/
		void upArrowPressed();

		/**
		* Metoda obslugujaca przycisk "dolnej strzalki" - umozliwia odczyt polozenia wszystkich wierzcholkow figury
		*/
		void downArrowPressed();

		/**
		* Metoda zapisuje aktualny stan obrazka do pliku myresult.png w katalogu biezacym
		*/
		void saveButtonPressed() const;

	private:
		sf::RenderWindow& m_window; //!< przechowuje obiekt ???
		tgui::Gui& m_gui; //!< przechowuje obiekt ???
		DrawFigures& m_loadedData; //!< Parametry wszystkich figur
		tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt"); //!< Motyw interfejsu
		int m_current_number; //!< Indeks aktualnej figury
		int m_current_vertex; //!< Indeks aktualnego wierzcholka

		tgui::EditBox::Ptr changeValues = theme->load("Editbox"); //!< Pole do wpisywania porzadanych parametrow figury
		tgui::ComboBox::Ptr selectParameterToChange = theme->load("ComboBox"); //!< Combobox - wybor parametru figury do zmiany
		tgui::Label::Ptr figureNumber = theme->load("Label"); //!< Napis "Selected Figure" na interfejsie
		tgui::Button::Ptr leftArrow = theme->load("Button"); //!< Przycisk wybiera poprzednia figure do modyfikacji
		tgui::Button::Ptr rightArrow = theme->load("Button"); //!< Przycisk wybiera kolejna figure do modyfikacji
		tgui::Label::Ptr currentPosition = theme->load("Label"); //!< Pole pokazuje jaka figura jest modyfikowana
		tgui::Label::Ptr changeOrder = theme->load("Label"); //!< Napis "Change Layer Order" na interfejsie
		tgui::Button::Ptr downArrow = theme->load("Button"); //!< Przycisk przesuwa aktualna warstwe pod spod
		tgui::Button::Ptr upArrow = theme->load("Button"); //!< Przycisk przesuwa aktualna warstwe na wierzch
		tgui::Label::Ptr figureName = theme->load("Label"); //!< Pole pokazuje rodzaj aktualnej figury
		tgui::Label::Ptr lineColorParameter = theme->load("Label"); //!< Napis "Outline Coler" na interfejsie + aktualna wartosc koloru linii obramowania
		tgui::Label::Ptr fulfilColorParameter = theme->load("Label"); //!< Napis "Fill Coler" na interfejsie + aktualna wartosc kolory wypelnienia
		tgui::Label::Ptr borderSizeParameter = theme->load("Label"); //!< Napis "Border" na interfejsie + aktualna wartosc koloru linii
		tgui::Label::Ptr opacityParameter = theme->load("Label"); //!< Napis "Opacity" na interfejsie + aktualna wartosc przezroczystosci
		tgui::Label::Ptr vertexesParameter = theme->load("Label"); //!< Napis "Vertex Coords" na interfejsie + aktualne wartosci wpolrzednych danego wierzcholka
		tgui::Button::Ptr refreshButton = theme->load("Button"); //!< Przycisk ktory wprowadza zmiany danego parametru wprowadzonego przez urzytkownika
		tgui::Button::Ptr upArrowVertex = theme->load("Button"); //!< Przycisk ktory umozilwia odczyt wierzcholka figury o wczesniejszym indeksie
		tgui::Button::Ptr downArrowVertex = theme->load("Button"); //!< Przycisk ktory umozliwia odczyt wierzcholka figury o kolejnym indeksie
		tgui::Button::Ptr saveButton = theme->load("Button"); //<! Przycik ktory umozliwia zapis aktualnego stanu obrazka w pliku myresult.png w katalagu biezacym
	};

}