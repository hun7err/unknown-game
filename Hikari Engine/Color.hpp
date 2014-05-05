#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include "Exception.hpp"

namespace Hikari
{
	class Color
	{
		public:
			Color(float red, float green, float blue, float alpha);
			
			float red(void);
			void red(float red);

			float green(void);
			void green(float green);

			float blue(void);
			void blue(float blue);

			float alpha(void);
			void alpha(float alpha);

			float* components(void);
			void components(float* components);

		private:
			float m_Red;
			float m_Green;
			float m_Blue;
			float m_Alpha;
	};
}

#endif // __COLOR_HPP__