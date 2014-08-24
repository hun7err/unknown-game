#ifndef __HIKARI_GRAPHICS_SHADERS_SHADERHPP__
#define __HIKARI_GRAPHICS_SHADERS_SHADERHPP__

#include "../../Helpers/ECS/Component.hpp"
#include "../../Core/ErrorCode.hpp"
#include "Input/ShaderInput.hpp"

#include <d3d10.h>
#include <d3d11.h>

namespace Hikari
{
	namespace Shaders
	{
		enum ShaderType
		{
			VERTEX_SHADER,
			PIXEL_SHADER,
			GEOMETRY_SHADER,
			COMPUTE_SHADER,
			HULL_SHADER,
			DOMAIN_SHADER
		};
	}

	class Shader : public Component
	{
		public:
			Shader( const std::string& ShaderName, Shaders::ShaderType shaderType );
			Shader( const std::wstring& filename, const std::string& ShaderName, Shaders::ShaderType shaderType );

			virtual ~Shader( void );

			virtual ErrorCode Compile( ID3D11Device *pDevice ) = 0;

			void SetEntryPoint( const std::string& entryPointName );
			void SetFileName( const std::wstring& filename );
			void SetShaderCode( const std::string& ShaderCode );

			Shaders::ShaderType GetShaderType( void ) const;

			ID3D10Blob *GetShaderBlob( void );
			void SetShaderBlob( ID3D10Blob *pShaderBlob );
				
			Shaders::ShaderInput *GetShaderInput( void );

		protected:
			Shaders::ShaderType m_ShaderType;
			ID3D10Blob* m_pShaderBlob;
			Shaders::ShaderInput *m_pShaderInput;
			std::string m_EntryPointName;

			bool m_FromFile;
			std::wstring m_Filename;

			bool m_FromString;
			std::string m_ShaderCode;
	};
}

#endif