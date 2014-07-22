#ifndef __D3D11_SHADER_PROGRAM_HPP__
#define __D3D11_SHADER_PROGRAM_HPP__

#include <string>

#include <d3d10_1.h>
#include <d3d11.h>

#include "D3D11System.hpp"

namespace Hikari
{
	class D3D11ShaderProgram
	{
		public:
			D3D11ShaderProgram();

			void setup(std::wstring vertexShaderName, std::wstring pixelShaderName);
			void setup(std::wstring shaderName);

			void cleanup(void);

			virtual ~D3D11ShaderProgram();

			void entryPointNames(std::string vertexShaderEntryPointName, std::string pixelShaderEntryPointName);
			void entryPointNames(std::string shaderEntryPointName);

			void d3d11system(D3D11System *pD3D11System);
			
			ID3D10Blob* vertexShaderBlob(void);
			ID3D10Blob* pixelShaderBlob(void);
			//ID3D10Blob* geometryShaderBlob(void);

			ID3D11VertexShader* vertexShader(void);
			ID3D11PixelShader* pixelShader(void);
			//ID3D11GeometryShader* geometryShader(void);

			ID3D11InputLayout* inputLayout(void);

			void compile(void);

		private:
			ID3D10Blob	*m_pVertexShaderBlob,
						*m_pPixelShaderBlob/*,
						*m_pGeometryShaderBlob*/;

			ID3D11VertexShader *m_pVertexShader;
			ID3D11PixelShader *m_pPixelShader;
			//ID3D11GeometryShader *m_pGeometryShader;

			ID3D11InputLayout *m_pInputLayout;

			D3D11_INPUT_ELEMENT_DESC m_InputElementDescription[3];
			D3D11_BUFFER_DESC matrixBufferDescription;

			std::wstring m_VertexShaderName,
						m_PixelShaderName/*,
						m_GeometryShaderName*/;

			LPCSTR m_VertexShaderEntryPointName, // dodaæ ew. gettery
					m_PixelShaderEntryPointName;

			D3D11System *m_pD3D11System;

			void compileAndCreateShaders(void);
			void setInputElementDescription(void);
	};
};



#endif // __D3D11_SHADER_PROGRAM_HPP__