cbuffer MVP
{
	matrix modelMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

struct VS_In
{
	float4 position : POSITION;
	float2 uv : TEXCOORD;
	//float3 normal : NORMAL;
};

struct PS_In
{
	float4 position : SV_POSITION;
	float2 uv : TEXCOORD;
	//float3 normal : NORMAL;
};

Texture2D diffuseTexture;
SamplerState shaderSamplerState;

PS_In VShader(VS_In input)
{
	PS_In output;

	output.position = input.position;
	output.uv = input.uv;
	//output.normal = input.normal;

	return output;
}

float4 PShader(PS_In input) : SV_TARGET
{
	float4 color = diffuseTexture.Sample(shaderSamplerState, input.uv);
	//float4 color = float4(1.0f,1.0f,1.0f,1.0f);
	return color;
}