#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <string>
#include <d3d11.h>

namespace Hikari
{
	/**
		\class Texture
		\brief Klasa bazowa, kt�r� rozszerza� powinny wszystkie klasy, kt�re maj� mie� funkcjonalno�� tekstur. Jest u�ywana tak�e do przechowywania element�w mened�era tekstur Hikari::TextureManager. Jej podstawow� metod� jest getter pola m_pShaderResourceView, kt�ry zwraca obiekt typu ID3D11ShaderResourceView
	*/
	class Texture
	{
		public:
			Texture();	///< Domy�lny konstruktor zeruj�cy pola i ustawiaj�cy nazw� na "NoName"
			Texture(std::string name);	///< Konstruktor zar�wno zeruj�cy pola jak i ustawiaj�cy nazw� tekstury
			virtual ~Texture();	///< Wirtualny destruktor, pozwala wywo�a� destruktor dla w�a�ciwej podklasy
			
			ID3D11ShaderResourceView *shaderResourceView(void);	///< Zwraca wska�nik do obiektu ID3D11ShaderResourceView b�d�cego wsp�lnym interfejsem dla wszystkich zasob�w u�ywanych przez shader (w tym tekstur)
			
			std::string name(void);	///< Pobiera nazw� jako std::string
			void name(std::string name);	///< Ustawia now� nazw� tekstury

		protected:
			std::string m_Name;
			ID3D11ShaderResourceView *m_pShaderResourceView;
	};
}

#endif // __TEXTURE_HPP__