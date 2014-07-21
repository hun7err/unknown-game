#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

/**
	\class Exception
	\brief Ogólna klasa wyj¹tku, aby stworzyæ nowy rodzaj wyj¹tku nale¿y dodaæ konstruktor a po nim :Exception(message, "nazwaKlasyWyj¹tku") { ... }
*/
class Exception
{
	public:
		char* message(void);	///< pobierz komunikat wyj¹tku
		char* type(void);		///< pobierz typ wyj¹tku w postaci ci¹gu znaków, np. WrongArgumentException

		Exception(char* pMessage, char* pType);	///< konstruktor wywo³ywany g³ównie przez klasy dziedzicz¹ce z Exception (ustawiaj¹ sta³e pType)

	private:
		char* m_pMessage;	///< komunikat wyj¹tku, krótki opis tego co posz³o Ÿle
		char* m_pType;		///< typ wyj¹tku, najlepiej jeœli bêdzie to nazwa klasy (np. WrongArgumentException, IllegalOperationException itp.)
};

#endif // __EXCEPTION_HPP__