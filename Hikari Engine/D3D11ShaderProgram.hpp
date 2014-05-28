#ifndef __D3D11_SHADER_PROGRAM_HPP__
#define __D3D11_SHADER_PROGRAM_HPP__

#include <string>

#include <d3d10.h>
#include <d3d11.h>

namespace Hikari
{
	class D3D11ShaderProgram
	{
		public:
			D3D11ShaderProgram(std::string vertexShaderName, std::string pixelShaderName/*, std::string geometryShaderName*/);

			void deviceContext(ID3D11DeviceContext *pDeviceContext);
			
			ID3D10Blob* vertexShaderBlob(void);
			ID3D10Blob* pixelShaderBlob(void);
			//ID3D10Blob* geometryShaderBlob(void);

			ID3D11VertexShader* vertexShader(void);
			ID3D11PixelShader* pixelShader(void);
			//ID3D11GeometryShader* geometryShader(void);

			void compile(void);

		private:
			ID3D10Blob	*m_pVertexShaderBlob,
						*m_pPixelShaderBlob/*,
						*m_pGeometryShaderBlob*/;

			ID3D11VertexShader *m_pVertexShader;
			ID3D11PixelShader *m_pPixelShader;
			//ID3D11GeometryShader *m_pGeometryShader;

			ID3D11DeviceContext *m_pDeviceContext;

			std::string m_VertexShaderName,
						m_PixelShaderName/*,
						m_GeometryShaderName*/;

			LPCSTR m_VertexShaderEntryPointName, // dodaæ g³ównie settery, ew. gettery
					m_PixelShaderEntryPointName;
	};
};



#endif // __D3D11_SHADER_PROGRAM_HPP__