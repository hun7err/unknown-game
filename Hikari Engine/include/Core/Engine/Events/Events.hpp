#ifndef __HIKARI_CORE_ENGINE_EVENTS_EVENTSHPP__
#define __HIKARI_CORE_ENGINE_EVENTS_EVENTSHPP__

namespace Hikari
{
	enum class Event
	{
		KeyPress,			// klawisz wci�ni�ty, jeszcze nie puszczony
		KeyRelease,			// puszczenie klawisza
		MouseMove,			// przesuni�cie myszy
		MouseClick,			// wci�ni�cie i puszczenie dowolnego przycisku myszy
		MouseButtonPress,	// wci�ni�cie dowolnego przycisku myszy
		MouseButtonRelease,	// puszczenie dowolnego przycisku myszy
		EVENTS_ITEM_COUNT	// MUSI by� ostatnie
	};
}

#endif