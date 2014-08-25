#ifndef __HIKARI_CORE_ERRORSHPP__
#define __HIKARI_CORE_ERRORSHPP__

namespace Hikari
{
	enum ErrorCode
	{
		SUCCESS = 0,

		NOT_IMPLEMENTED_YET,

		TEXTURE2D_CREATE_TEXTURE2D_FAILED,
		TEXTURE2D_CREATE_RENDER_TARGET_VIEW_FAILED,
		TEXTURE2D_CREATE_SHADER_RESOURCE_VIEW_FAILED,
		TEXTURE2D_PDESCRIPTION_IS_NULL,
		TEXTURE2D_IL_LOAD_IMAGE_FAILED,

		FILE_NOT_FOUND,

		SHADER_COMPILATION_FAILED,
		SHADER_COMPILATION_FAILED_EMPTY_SHADER,
		SHADER_CREATE_SHADER_FAILED,
		SHADER_INPUTELEMENT_LAYOUT_CREATION_FAILED,
		SHADER_SAMPLERSTATE_CREATION_FAILED,
		SHADER_MODELVIEWPROJECTION_CREATE_BUFFER_FAILED,

		GEOMETRY_VERTEX_ARRAY_NULL,
		GEOMETRY_INDEX_ARRAY_NULL,
		GEOMETRY_VERTEX_BUFFER_CREATION_FAILED,
		GEOMETRY_INDEX_BUFFER_CREATION_FAILED,

		MANAGER_INVALID_KEY,
		MANAGER_OUTDATED_HANDLE,

		WORLD_SCENE_NOT_FOUND
	};
}

#endif