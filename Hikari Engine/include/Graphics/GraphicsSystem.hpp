#ifndef __GRAPHICSSYSTEMHPP__
#define __GRAPHICSSYSTEMHPP__

#include "../Helpers/ECS/System.hpp"
#include <vector>

namespace Hikari
{
	class GraphicsSystem : public System
	{
		public:
			void Init( Engine *pEngine );
			void Update( float dt );

		private:
			Engine *m_pEngine;
	};
}

#endif