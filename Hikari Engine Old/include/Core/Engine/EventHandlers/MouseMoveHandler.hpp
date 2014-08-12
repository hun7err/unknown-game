#ifndef __HIKARI_CORE_ENGINE_EVENTHANDLERS_MOUSEMOVEHANDLERHPP__
#define __HIKARI_CORE_ENGINE_EVENTHANDLERS_MOUSEMOVEHANDLERHPP__

#include "../../../Core/Engine/EventHandlers/EventHandler.hpp"

#include <functional>

namespace Hikari
{
	namespace EventHandlers
	{
		class MouseMoveHandler : public Hikari::EventHandler
		{
			public:
				MouseMoveHandler();

				void process();

				void handlerFunction(std::function<void(int, int)> newHandlerFunction);
				void x(int x);
				void y(int x);
				void cursorPosition(int x, int y);

			private:
				std::function<void(int, int)> m_eventHandlerFunction;

				int m_x,
					m_y,
					m_dx,
					m_dy;
		};
	}
}

#endif