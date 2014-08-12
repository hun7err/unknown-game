#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include <DirectXPackedVector.h>
#include <string>

#include "../../Core/Managers/Handles/HTexture.hpp"
#include "../../Core/managers/Handles/HShader.hpp"

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
			void diffuseMap(HTexture hNewDiffuseMap);

			HTexture specularMap(void);
			void specularMap(HTexture hNewSpecularMap);

			HTexture normalMap(void);
			void normalMap(HTexture hNewNormalMap);

			HTexture bumpMap(void);
			void bumpMap(HTexture hNewBumpMap);

			HShader shader(void);
			void shader(HShader hNewShader);

		private:
			void initialize(void);

			std::string m_Name;
			DirectX::XMVECTORF32 m_DiffuseColor,
								 m_SpecularColor,
								 m_AmbientColor,
								 m_EmissiveColor;

			HTexture m_hDiffuseMap,
					 m_hBumpMap,
					 m_hSpecularMap,
					 m_hNormalMap;

			HShader m_hShaderProgram;

			float m_Shininess;

			// doda� tekstury odpowiednie (dla diffuse, specular itp.), ale to w swoim czasie
			// dodatkowo mo�na by by�o trzyma� id materia�u w teksturze, co pozwoli�oby miesza� ze sob� wiele materia��w
	};
}

#endif // __MATERIAL_HPP__