#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include <DirectXPackedVector.h>
#include <string>

#include "HTexture.hpp"
#include "HShader.hpp"

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
			void diffuseColor(float r, float g, float b, float a);

			DirectX::XMVECTORF32 specularColor(void);
			void specularColor(DirectX::XMVECTORF32 *newSpecularColor);
			void specularColor(float r, float g, float b, float a);

			DirectX::XMVECTORF32 ambientColor(void);
			void ambientColor(DirectX::XMVECTORF32 *newAmbientColor);
			void ambientColor(float r, float g, float b, float a);

			DirectX::XMVECTORF32 emissiveColor(void);
			void emissiveColor(DirectX::XMVECTORF32 *newEmissiveColor);
			void emissiveColor(float r, float g, float b, float a);

			HTexture diffuseMap(void);
			void diffuseMap(HTexture newDiffuseMap);

			HTexture specularMap(void);
			void specularMap(HTexture newSpecularMap);

			HTexture normalMap(void);
			void normalMap(HTexture newNormalMap);

			HTexture bumpMap(void);
			void bumpMap(HTexture newBumpMap);

			HShader shader(void);
			void shader(HShader newShaderHandle);
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

			HShader m_ShaderProgramHandle;

			float m_Shininess;

			// dodaæ tekstury odpowiednie (dla diffuse, specular itp.), ale to w swoim czasie
			// dodatkowo mo¿na by by³o trzymaæ id materia³u w teksturze, co pozwoli³oby mieszaæ ze sob¹ wiele materia³ów
	};
}

#endif // __MATERIAL_HPP__