#ifndef __HIKARI_CORE_ENGINE_EVENTS_EVENTSHPP__
#define __HIKARI_CORE_ENGINE_EVENTS_EVENTSHPP__

namespace Hikari
{
	enum class Event
	{
		KeyPress,			// klawisz wciœniêty, jeszcze nie puszczony
		KeyRelease,			// puszczenie klawisza
		MouseMove,			// przesuniêcie myszy
		MouseClick,			// wciœniêcie i puszczenie dowolnego przycisku myszy
		MouseButtonPress,	// wciœniêcie dowolnego przycisku myszy
		MouseButtonRelease,	// puszczenie dowolnego przycisku myszy
		EVENTS_ITEM_COUNT	// MUSI byæ ostatnie
	};
}

#endif