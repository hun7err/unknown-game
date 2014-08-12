#ifndef __MOUSEEVENTHPP__
#define __MOUSEEVENTHPP__

namespace Hikari
{
	namespace Events
	{
		namespace MouseEvent	// 0x0006 - 0x000f
		{
			const short int LeftButtonPress		= 0x0006,
							LeftButtonRelease	= 0x0007,
							LeftButtonClick		= 0x0008,
							RightButtonPress	= 0x0009,
							RightButtonRelease	= 0x000a,
							RightButtonClick	= 0x000b,
							Move				= 0x000c;
		}
	}
}

#endif