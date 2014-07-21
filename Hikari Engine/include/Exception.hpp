#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

/**
	\class Exception
	\brief Og�lna klasa wyj�tku, aby stworzy� nowy rodzaj wyj�tku nale�y doda� konstruktor a po nim :Exception(message, "nazwaKlasyWyj�tku") { ... }
*/
class Exception
{
	public:
		char* message(void);	///< pobierz komunikat wyj�tku
		char* type(void);		///< pobierz typ wyj�tku w postaci ci�gu znak�w, np. WrongArgumentException

		Exception(char* pMessage, char* pType);	///< konstruktor wywo�ywany g��wnie przez klasy dziedzicz�ce z Exception (ustawiaj� sta�e pType)

	private:
		char* m_pMessage;	///< komunikat wyj�tku, kr�tki opis tego co posz�o �le
		char* m_pType;		///< typ wyj�tku, najlepiej je�li b�dzie to nazwa klasy (np. WrongArgumentException, IllegalOperationException itp.)
};

#endif // __EXCEPTION_HPP__