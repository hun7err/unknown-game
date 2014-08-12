#define _USE_MATH_DEFINES
#include <cmath>
// z jakiego� powodu to musi by� na samej g�rze. Kocham STL <3

#include "../../../include/Core/Objects/Sphere.hpp"

Hikari::Objects::Sphere::Sphere(const Vector3D& center, float radius, unsigned int segments, unsigned int rings) : Object()
{
	m_VertexCount = 2 + rings*segments;
	m_IndexCount = 6 * rings * segments;

	m_pVertices = new Vertex [m_VertexCount];
	m_pIndices = new unsigned long [m_IndexCount];

	/*
		to-do:
		- wyliczanie normalnych (znormalizowanych)
		- wyliczanie UV:
			u = 0.5 + atan2(d_z, d_x) / pi_2;
			v = 0.5 - asin(d_y) / pi;

			d = wektor jednostkowy od P (x,y,z na kuli) do �rodka kuli
	*/

	// "czubek" na dodatnim Z
	m_pVertices[0].position_modelSpace = Vector3D(center.x(), -radius + center.y(), center.z());
	
	float	pi_2 = (float)M_PI_2,
			pi = (float)M_PI;

	unsigned int cur_pos = 1,
				r = 1,
				s;
	float	r_f = pi/(float)(rings+1),
			s_f = 2.0f*pi/(float)segments;

	Vector3D d;

	// pocz�tek generacji wierzcho�k�w

	for(; r < rings + 1; r++)
	{
		for(s = 0; s < segments; s++)
		{
			// wierzcho�ek w przestrzeni modelu
			m_pVertices[cur_pos].position_modelSpace.x( radius * cos(s_f * (float)s) * cos(-pi_2 + r_f * (float)r) + center.x() );
			m_pVertices[cur_pos].position_modelSpace.y( radius * sin(-pi_2 + r_f * (float)r) + center.y() );
			m_pVertices[cur_pos].position_modelSpace.z( radius * sin(s_f * (float)s) * cos(-pi_2 + r_f * (float)r) + center.z() );
			
			// UV wierzcho�k�w
			d = Vector3D(m_pVertices[cur_pos].position_modelSpace, center);
			m_pVertices[cur_pos].uv.x(0.5f + (float)atan2(d.x(), d.y()) / pi_2);
			m_pVertices[cur_pos].uv.y(0.5f + (float)asin(d.y()) / pi);
			
			// wektor normalny wierzcho�ka w przestrzeni modelu
			//m_pVertices[cur_pos].normal_modelSpace = m_pVertices[cur_pos].position_modelSpace - center;
			//m_pVertices[cur_pos].normal_modelSpace.normalize();

			cur_pos++;
		}
	}

	// "sp�d" na ujemnym Z
	m_pVertices[m_VertexCount-1].position_modelSpace = Vector3D(center.x(), radius + center.y(), center.z());

	// koniec generacji wierzcho�k�w
	// pocz�tek generacji indeks�w (tr�jk�t�w)

	cur_pos = 0;

	for(s = 1; s <= segments; s++)
	{
		m_pIndices[cur_pos] = 0;
		m_pIndices[cur_pos+1] = s;
		m_pIndices[cur_pos+2] = s+1 > segments ? 1 : s+1;

		cur_pos += 3;
	}

	int t1, t2, t3;

	for(s = 1; s <= (rings-1)*segments; s++)
	{
		t1 = s;
		t2 = s + segments;
		t3 = s % segments > 0 ? s + segments + 1 : s + 1;

		// pierwszy tr�jk�t

		m_pIndices[cur_pos] = t1;
		m_pIndices[cur_pos+1] = t2;
		m_pIndices[cur_pos+2] = t3;

		// drugi tr�jk�t

		m_pIndices[cur_pos+3] = t1;
		m_pIndices[cur_pos+4] = s % segments == 0 ? s + 1 - segments : s + 1;
		m_pIndices[cur_pos+5] = t3;

		cur_pos += 6;
	}

	r = m_VertexCount - segments - 1;
	for(s = 0; s < segments; s++)
	{
		m_pIndices[cur_pos] = m_VertexCount-1;
		m_pIndices[cur_pos+1] = r + s;
		m_pIndices[cur_pos+2] = s + 1 == segments ? m_VertexCount - segments - 1 : m_VertexCount - segments + s;

		cur_pos += 3;
	}

	// wyliczy� wektory normalne (patrz: Swift.Engine src/Sphere.cpp)
}

Hikari::Objects::Sphere::~Sphere()
{
	delete [] m_pVertices;
	m_pVertices = nullptr;
	delete [] m_pIndices;
	m_pIndices = nullptr;
}
