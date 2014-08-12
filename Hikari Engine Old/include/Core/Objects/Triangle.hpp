#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

/**
	\file	Triangle.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-23
*/

#include "../../Core/Objects/Object.hpp"

namespace Hikari
{
	/**
		\brief Obiekty, które mog¹ zostaæ wyrenderowane. Aby to siê jednak sta³o, musz¹ znajdowaæ siê w mened¿erze obiektów (Hikari::ObjectManager) i byæ widoczne (domyœlnie s¹, do zmiany u¿ywana jest metoda visible() ). Musz¹ rozszerzaæ klasê Hikari::Object
	*/
	namespace Objects
	{
		/**
			\class	Triangle
			\brief	Obiekt trójk¹ta w przestrzeni 3D
		*/
		class Triangle : public Object
		{
			public:
				Triangle(const Vector3D& first_vertex, const Vector3D& second_vertex, const Vector3D& third_vertex);

				virtual ~Triangle();
		};

		class EquilateralTriangle : public Triangle
		{
			public:
				EquilateralTriangle(const Vector3D& triangleCenter, float sideLength);
		};
	}
}

#endif // __TRIANGLE_HPP__