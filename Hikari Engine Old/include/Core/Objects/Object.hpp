#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <string>

#include <d3d11.h>
#include <DirectXMath.h>

#include "../../Helpers/Vector.hpp"
#include "../../Core/Managers/Handles/HMaterial.hpp"

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
			void draw(DirectX::XMFLOAT4X4 transformation); // virtual? (raczej nie)
			void cleanup(void);

			unsigned int vertexCount(void);
			unsigned int indexCount(void);

			HMaterial material(void);
			void material(HMaterial hMaterial);

		protected:
			struct Vertex {
				Hikari::Vector3D position_modelSpace;
				Hikari::Vector2D uv;
				Hikari::Vector3D normal_modelSpace;
			};

			struct MatrixType
			{
				DirectX::XMMATRIX model;
				DirectX::XMMATRIX view;
				DirectX::XMMATRIX projection;
			};

			Vertex *m_pVertices;
			unsigned long *m_pIndices;

			unsigned int m_VertexCount,
						 m_IndexCount;
			D3D11_PRIMITIVE_TOPOLOGY m_PrimitiveTopology;

			std::string m_Name;
			ID3D11Buffer *m_pVertexBuffer, *m_pIndexBuffer;

			HMaterial m_hMaterial;

			DirectX::XMFLOAT4X4 m_TransformationMatrix;

		private:
			void initialize(void);
	};
}

#endif // __OBJECT_HPP__