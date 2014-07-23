struct VIn
{
	float4 position : POSITION;
	float2 uv : TEXCOORD;
	float3 normal : NORMAL;
};

struct VOut
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

VOut VShader(VIn input)
{
	VOut output;

	output.position = input.position;
	output.color = float4(1.0f,1.0f,1.0f,1.0f);

	return output;
}

float4 PShader(float4 position : SV_POSITION, float4 color : COLOR) : SV_TARGET
{
	return color;
}