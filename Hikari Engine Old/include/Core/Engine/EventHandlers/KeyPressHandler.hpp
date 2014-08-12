#ifndef __HIKARI_CORE_ENGINE_EVENTHANDLERS_KEYPRESSHANDLERHPP__
#define __HIKARI_CORE_ENGINE_EVENTHANDLERS_KEYPRESSHANDLERHPP__

#include "../../../Core/Engine/EventHandlers/EventHandler.hpp"
#include <functional>

namespace Hikari
{
	/**
		\brief Wszystkie klasy, które pozwalaj¹ na obs³ugê wydarzeñ, co z kolei mo¿liwe jest przez implementacjê interfejsu Hikari::EventHandler
	*/
	namespace EventHandlers
	{
		class KeyPressHandler : public Hikari::EventHandler
		{
			public:
				KeyPressHandler();

				void process();
				void handlerFunction(std::function<void(int)> newHandler);
				void keyCode(int code);

			private:
				int m_KeyCode;
				std::function<void(int)> m_eventHandlerFunction;

		};
	}
}

#endif