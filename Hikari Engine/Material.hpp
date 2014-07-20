#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include <DirectXPackedVector.h>
#include "D3D11ShaderProgram.hpp"
#include "HTexture.hpp"
#include <string>

namespace Hikari
{
	class Material
	{
		public:
			Material();
			Material(std::string name);

			virtual ~Material();

			std::string name(void);
			void name(std::string name);

			DirectX::XMVECTORF32 diffuseColor(void);
			void diffuseColor(DirectX::XMVECTORF32 *newDiffuseColor);

			DirectX::XMVECTORF32 specularColor(void);
			void specularColor(DirectX::XMVECTORF32 *newSpecularColor);

			DirectX::XMVECTORF32 ambientColor(void);
			void ambientColor(DirectX::XMVECTORF32 *newAmbientColor);

			DirectX::XMVECTORF32 emissiveColor(void);
			void emissiveColor(DirectX::XMVECTORF32 *newEmissiveColor);

			HTexture diffuseMap(void);
			void diffuseMap(HTexture newDiffuseMap);

			HTexture specularMap(void);
			void specularMap(HTexture newSpecularMap);

			HTexture normalMap(void);
			void normalMap(HTexture newNormalMap);

			HTexture bumpMap(void);
			void bumpMap(HTexture newBumpMap);
		private:
			void initialize(void);

			std::string m_Name;
			DirectX::XMVECTORF32 m_DiffuseColor,
								 m_SpecularColor,
								 m_AmbientColor,
								 m_EmissiveColor;

			HTexture m_DiffuseMap,
					 m_BumpMap,
					 m_SpecularMap,
					 m_NormalMap;

			D3D11ShaderProgram m_ShaderProgram;

			float m_Shininess;

			// doda� tekstury odpowiednie (dla diffuse, specular itp.), ale to w swoim czasie
			// dodatkowo mo�na by by�o trzyma� id materia�u w teksturze, co pozwoli�oby miesza� ze sob� wiele materia��w
	};
}

#endif // __MATERIAL_HPP__