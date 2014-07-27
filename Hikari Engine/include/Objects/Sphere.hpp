#ifndef __SPHEREHPP__
#define __SPHEREHPP__

/**
	\file	Sphere.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-26
*/

#include "../Object.hpp"

namespace Hikari
{
	namespace Objects
	{
		class Sphere : public Object
		{
			public:
				Sphere(const Vector3D& center, double radius, unsigned int segments, unsigned int rings);

				~Sphere();
		};
	}
}

#endif // __SPHEREHPP__