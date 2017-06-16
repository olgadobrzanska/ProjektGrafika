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
		* \brief Konstruktor interfejsu uzytkownika
		* \param[in] window Okno w ktorym generowane jest GUI\n Potrzebne do robienia zrzutu ekranu
		* \param[in] gui Interfejs obslugujacy komunikacje z uzytkownikiem
		* \param[in] loadedData Zmienna przechowywujaca parametry wszystkich figur
		*/
		Panel(sf::RenderWindow& window, tgui::Gui& gui, DrawFigures& loadedData);

		/**
		* \brief Uaktualnianie interfejsu po kazdej zmianie wartosci
		*/
		void updatePanel() const;

		/**
		* \brief Zmiana aktualnie obslugiwanej figury na poprzednia
		*/
		void leftArrowPressed();

		/**
		* \brief Zmiana aktualnie obslugiwanej figury na nastepna
		*/
		void rightArrowPressed();
		
		/**
		* \brief Przesuniecie aktualnie obslugiwanej figury jedna warstwe wyzej
		*/
		void upArrowVertexPressed();

		/**
		* \brief Przesuniecie aktualnie obslugiwanej figury jedna warstwe nizej
		*/
		void downArrowVertexPressed();

		/**
		* \brief Uaktualnienie wypisywanej nazwy aktualnie obslugiwanej figury
		*/
		void updateFigureName() const;

		/**
		* \brief Wypisanie koloru obramowania wybranej figury
		*/
		void updateOutlineColorInfo() const;

		/**
		* \brief Wypisanie koloru wypelnienia wybranej figury
		*/
		void updateFillColorInfo() const;

		/**
		* \brief Wypisanie grubosci obramowania wybranej figury
		* 
		* W przypadku linii (#DrawFigures.FigType LINE) wypisywana jest grubosc linii
		*/
		void updateBorderSize() const;

		/**
		* \brief Wypisanie przezroczystoci wybranej figury
		*/
		void updateOpacity() const;

		/**
		* \brief Wypisanie informacji o wierzcholkach figury
		* \sa DrawFigures.m_loadedfigures_data
		*/
		void updateVertexes() const;

		/**
		* \brief Obsluga wyboru zmienianego parametru figury
		* 
		* Na podstawie wyboru w comboboxie generowana jest podpowiedz, w jaki sposob nalezy uzupelnic 
		* textbox znajdujacy sie ponizej oraz w odpowiedni sposob obslugiwane jest zapisanie ustawien.
		*/
		void checkParameterToChange() const;

		/**
		* \brief Zapisanie wprowadzonych do textboxa danych
		* 
		* Tresc TextBoxa jest kasowana, jesli zapis odbyl sie poprawnie\n
		* W przeciwnym razie zawartosc textboxa nie jest kasowana.
		*/
		void refreshButtonPressed() const;

		/**
		* \brief Poruszanie sie po liscie wierzcholkow w gore
		*/
		void upArrowPressed();

		/**
		* \brief Poruszanie sie po liscie wierzcholkow w dol
		*/
		void downArrowPressed();

		/**
		* \brief Wykonanie zrzutu ekranu wyrysowanych figur
		* 
		* Zrzut ekranu jest zapisywany do pliku myresult.bmp w katalogu, w ktorym znajduje 
		* sie plik wykonywalny.
		*/
		void saveButtonPressed() const;

	private:
		sf::RenderWindow& m_window; //!< Okno w ktorym rysowane jest GUI
		tgui::Gui& m_gui; //!< GUI sluzace do komunikacji z uzytkownikiem
		DrawFigures& m_loadedData; //!< Parametry wszystkich figur
		tgui::Theme::Ptr theme = tgui::Theme::create("theme/Black.txt"); //!< Motyw interfejsu
		int m_current_number; //!< Indeks aktualnej figury
		int m_current_vertex; //!< Indeks aktualnego wierzcholka
		
		/**
		* \brief Przygotowanie interfejsu uzytkownika
		*/
		void preparePanel();

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