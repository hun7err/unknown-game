#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

/**
	\file	Triangle.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-23
*/

#include "../Object.hpp"

namespace Hikari
{
	namespace Objects
	{
		/**
			\class	Triangle
			\brief	Obiekt trójk¹ta w przestrzeni 3D
		*/
		class Triangle : public Object
		{
			public:
				Triangle(Hikari::Vector3D first_vertex, Hikari::Vector3D second_vertex, Hikari::Vector3D third_vertex);

				virtual ~Triangle();
		};

		class EquilateralTriangle : public Triangle
		{
			public:
				EquilateralTriangle(Hikari::Vector3D triangleCenter, float sideLength);
		};
	}
}

#endif // __TRIANGLE_HPP__