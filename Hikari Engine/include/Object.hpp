#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <string>

#include <d3d11.h>

#include "Vector.hpp"
#include "HMaterial.hpp"

namespace Hikari
{
	class Object
	{
		public:
			Object();
			Object(std::string name);

			virtual ~Object();

			std::string name(void);
			void name(std::string name);

			void setup(void);
			void draw(void); // virtual? (raczej nie)
			void cleanup(void);

			unsigned int vertexCount(void);
			unsigned int indexCount(void);

			HMaterial material(void);
			void material(HMaterial materialHandle);

		protected:
			struct Vertex {
				Hikari::Vector3D position_modelSpace;
				Hikari::Vector2D uv;
				Hikari::Vector3D normal_modelSpace;
			};

			Vertex *m_pVertices;
			unsigned long *m_pIndices;

			unsigned int m_VertexCount,
						 m_IndexCount;
			D3D11_PRIMITIVE_TOPOLOGY m_PrimitiveTopology;

			std::string m_Name;
			ID3D11Buffer *m_pVertexBuffer, *m_pIndexBuffer;

			HMaterial m_MaterialHandle;

		private:
			void initialize(void);
	};
}

#endif // __OBJECT_HPP__