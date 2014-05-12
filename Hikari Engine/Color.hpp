#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include "Exception.hpp"

namespace Hikari
{
	class Color
	{
		public:
			Color(float red, float green, float blue, float alpha);	///< domyœlny konstruktor ustawiaj¹cy wartoœci poszczególnych komponentów RGBA (wszystkie zmiennoprzecinkowe <0.0f, 1.0f>
			
			float red(void);		///< pobiera sk³adow¹ R (czerwony), a jeœli to konieczne, przed zwrócenie przycina wartoœæ do zakresu <0.0f, 1.0f>
			void red(float red);	///< ustawia wartoœæ sk³adowej R (czerwonego) na wartoœæ parametru red

			float green(void);		///< pobiera sk³adow¹ G (zielony), a jeœli to konieczne, przed zwrócenie przycina wartoœæ do zakresu <0.0f, 1.0f>
			void green(float green);///< ustawia wartoœæ sk³adowej G (zielonego) na wartoœæ parametru green

			float blue(void);		///< pobiera sk³adow¹ B (niebieski), a jeœli to konieczne, przed zwrócenie przycina wartoœæ do zakresu <0.0f, 1.0f>
			void blue(float blue);	///< ustawia wartoœæ sk³adowej B (niebieskiego) na wartoœæ parametru blue

			float alpha(void);		///< pobiera sk³adow¹ A (alpha/opacity/krycie/przezroczystoœæ), a jeœli to konieczne, przed zwrócenie przycina wartoœæ do zakresu <0.0f, 1.0f>
			void alpha(float alpha);///< ustawia wartoœæ sk³adowej A (alpha/krycie/opacity/przezroczystoœæ) na wartoœæ parametru alpha

			float* components(void);///< zwraca wskaŸnik na komponent R zwracaj¹c tym samym wskaŸnik na 4 komponenty RGBA
			void components(float* pComponents);	///< ustawia komponenty na 4 wartoœci znajduj¹ce siê w ci¹g³ym obszarze pamiêci pocz¹wszy od pComponents; jeœli wskaŸnik lub dowolny z komponentów czyli pComponents+(1,2,3) jest NULLem, zostanie rzucony wyj¹tek typu NullPointerException

		private:
			float m_Red;
			float m_Green;
			float m_Blue;
			float m_Alpha;
	};
}

#endif // __COLOR_HPP__