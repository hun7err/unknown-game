#ifndef __HIKARI_GRAPHICS_GRAPHICSSYSTEMHPP__
#define __HIKARI_GRAPHICS_GRAPHICSSYSTEMHPP__

#include "../Helpers/ECS/System.hpp"
#include "DirectX/Direct3D11SubSystem.hpp"
#include "Renderers/Renderer.hpp"
#include <vector>

namespace Hikari
{
	class GraphicsSystem : public System
	{
		public:
			GraphicsSystem( void );
			~GraphicsSystem( void );

			void Init( Engine *pEngine );
			void Update( float dt );

		private:
			Engine *m_pEngine;
			Direct3D11SubSystem *m_pD3D11SubSystem;
			Renderer *m_pRenderer;
	};
}

#endif