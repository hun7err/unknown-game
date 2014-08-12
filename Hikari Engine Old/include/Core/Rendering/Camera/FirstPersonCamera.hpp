#ifndef __HIKARI_CORE_RENDERING_CAMERA_FIRSTPERSONCAMERAHPP__
#define __HIKARI_CORE_RENDERING_CAMERA_FIRSTPERSONCAMERAHPP__

#include "../../../Core/Rendering/Camera/Camera.hpp"
#include "../../../Core/Engine/EventHandlers/MouseMoveHandler.hpp"
#include "../../../Core/Managers/Handles/HEventHandler.hpp"

// przerzuciæ pitch,yaw(,roll) do Camera + zmieniæ position() na move()

namespace Hikari
{
	/**
		\brief Kamery, pomagaj¹ wyrenderowaæ obraz z danego punktu sceny oraz daj¹ u¿ytkownikowi mo¿liwoœæ sterowania punktem widzenia. Implementuj¹ interfejs Hikari::Camera
	*/
	namespace Cameras
	{
		class FirstPersonCamera : public Hikari::Camera
		{
			public:
				FirstPersonCamera();				

				void tick(void);
				void setBindings(void);
				void disableBindigs(void);

				~FirstPersonCamera();

			private:
				Hikari::EventHandlers::MouseMoveHandler m_mouseMoveHandler;
				Hikari::HEventHandler *m_phEventHandler;
		};
	}
}

#endif