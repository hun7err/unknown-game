#ifndef __CUBEHPP__
#define __CUBEHPP__

/**
	\file	Cube.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-26
*/

#include "../../Core/Objects/Object.hpp"

namespace Hikari
{
	namespace Objects
	{
		class Cube : public Object
		{
			public:
				Cube(const Vector3D& center, float sideLength);
				~Cube();
		};
	}
}

#endif // __CUBEHPP__