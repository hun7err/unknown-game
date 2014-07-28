#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <string>
#include <d3d11.h>

namespace Hikari
{
	/**
		\class Texture
		\brief Klasa bazowa, któr¹ rozszerzaæ powinny wszystkie klasy, które maj¹ mieæ funkcjonalnoœæ tekstur. Jest u¿ywana tak¿e do przechowywania elementów mened¿era tekstur Hikari::TextureManager. Jej podstawow¹ metod¹ jest getter pola m_pShaderResourceView, który zwraca obiekt typu ID3D11ShaderResourceView
	*/
	class Texture
	{
		public:
			Texture();	///< Domyœlny konstruktor zeruj¹cy pola i ustawiaj¹cy nazwê na "NoName"
			Texture(std::string name);	///< Konstruktor zarówno zeruj¹cy pola jak i ustawiaj¹cy nazwê tekstury
			virtual ~Texture();	///< Wirtualny destruktor, pozwala wywo³aæ destruktor dla w³aœciwej podklasy
			
			ID3D11ShaderResourceView *shaderResourceView(void);	///< Zwraca wskaŸnik do obiektu ID3D11ShaderResourceView bêd¹cego wspólnym interfejsem dla wszystkich zasobów u¿ywanych przez shader (w tym tekstur)
			
			std::string name(void);	///< Pobiera nazwê jako std::string
			void name(std::string name);	///< Ustawia now¹ nazwê tekstury

		protected:
			std::string m_Name;
			ID3D11ShaderResourceView *m_pShaderResourceView;
	};
}

#endif // __TEXTURE_HPP__