#ifndef __BOXHPP__
#define __BOXHPP__

/**
	\file	Box.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-26
*/

#include "../Object.hpp"

namespace Hikari
{
	namespace Objects
	{
		class Box : public Object
		{
			public:
				Box(const Vector3D& center, double height, double width, double depth);
		};
	}
}

#endif // __BOXHPP__