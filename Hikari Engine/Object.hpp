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

			virtual void setup(ID3D11Device* pDevice) = 0;
			void draw(ID3D11DeviceContext* pDeviceContext); // virtual?
			void cleanup(void);

			unsigned int vertexCount(void);
			unsigned int indexCount(void);

			HMaterial material(void);
			void material(HMaterial materialHandle);

		protected:
			unsigned int m_VertexCount,
						 m_IndexCount;
			D3D11_PRIMITIVE_TOPOLOGY m_PrimitiveTopology;

			void initialize(void);

			std::string m_Name;
			ID3D11Buffer *m_pVertexBuffer, *m_pIndexBuffer;

			HMaterial m_MaterialHandle;

			struct Vertex {
				Hikari::Vector3D position_modelSpace;
				Hikari::Vector2D uv;
				Hikari::Vector3D normal_modelSpace;
			};
	};
}

#endif // __OBJECT_HPP__