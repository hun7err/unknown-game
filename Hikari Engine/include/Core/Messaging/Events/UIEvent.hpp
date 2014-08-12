#ifndef __UIEVENTHPP__
#define __UIEVENTHPP__

namespace Hikari
{
	namespace Events
	{
		namespace UIEvent	// 0x0010 - 0x003f
		{
			const short int WindowMove			= 0x0010,
							WindowResize		= 0x0011,
							WindowClose			= 0x0012,
							WindowMinimize		= 0x0013,
							WindowMaximize		= 0x0014,
							WindowTitleBarClick	= 0x0015,
							ButtonPress			= 0x0016,
							SliderValueChange	= 0x0017;	// i wiele, wiele wiêcej do zrobienia
		}
	}
}

#endif