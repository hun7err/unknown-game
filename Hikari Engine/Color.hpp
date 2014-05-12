#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include "Exception.hpp"

namespace Hikari
{
	class Color
	{
		public:
			Color(float red, float green, float blue, float alpha);	///< domy�lny konstruktor ustawiaj�cy warto�ci poszczeg�lnych komponent�w RGBA (wszystkie zmiennoprzecinkowe <0.0f, 1.0f>
			
			float red(void);		///< pobiera sk�adow� R (czerwony), a je�li to konieczne, przed zwr�cenie przycina warto�� do zakresu <0.0f, 1.0f>
			void red(float red);	///< ustawia warto�� sk�adowej R (czerwonego) na warto�� parametru red

			float green(void);		///< pobiera sk�adow� G (zielony), a je�li to konieczne, przed zwr�cenie przycina warto�� do zakresu <0.0f, 1.0f>
			void green(float green);///< ustawia warto�� sk�adowej G (zielonego) na warto�� parametru green

			float blue(void);		///< pobiera sk�adow� B (niebieski), a je�li to konieczne, przed zwr�cenie przycina warto�� do zakresu <0.0f, 1.0f>
			void blue(float blue);	///< ustawia warto�� sk�adowej B (niebieskiego) na warto�� parametru blue

			float alpha(void);		///< pobiera sk�adow� A (alpha/opacity/krycie/przezroczysto��), a je�li to konieczne, przed zwr�cenie przycina warto�� do zakresu <0.0f, 1.0f>
			void alpha(float alpha);///< ustawia warto�� sk�adowej A (alpha/krycie/opacity/przezroczysto��) na warto�� parametru alpha

			float* components(void);///< zwraca wska�nik na komponent R zwracaj�c tym samym wska�nik na 4 komponenty RGBA
			void components(float* pComponents);	///< ustawia komponenty na 4 warto�ci znajduj�ce si� w ci�g�ym obszarze pami�ci pocz�wszy od pComponents; je�li wska�nik lub dowolny z komponent�w czyli pComponents+(1,2,3) jest NULLem, zostanie rzucony wyj�tek typu NullPointerException

		private:
			float m_Red;
			float m_Green;
			float m_Blue;
			float m_Alpha;
	};
}

#endif // __COLOR_HPP__