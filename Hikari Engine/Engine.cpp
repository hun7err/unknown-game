#include "Engine.hpp"
#include "Exception.hpp"

Hikari::Engine::Engine(void)
{
	m_pRenderer = NULL;
	m_pObjectManager = NULL;
}

void Hikari::Engine::setup(void)
{

	// m_pRenderer = new Hikari::
	objectManagerMutex.lock();
	m_pObjectManager = new Hikari::Manager<Object>();
	objectManagerMutex.unlock();
	materialManagerMutex.lock();
	m_pMaterialManager = new Hikari::Manager<Material>();
	materialManagerMutex.unlock();
	m_pObjectManager->setup();
	m_pMaterialManager->setup();
}

void Hikari::Engine::cleanup(void)
{
	objectManagerMutex.lock();
	m_pObjectManager->cleanup();
	delete m_pObjectManager;
	m_pObjectManager = NULL;
	objectManagerMutex.unlock();

	materialManagerMutex.lock();
	m_pMaterialManager->cleanup();
	delete m_pMaterialManager;
	m_pMaterialManager = NULL;
	materialManagerMutex.unlock();

}

LRESULT CALLBACK Hikari::WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
		default:
		{
			return EngineHandle->MessageHandler(WindowHandle, message, wParam, lParam);
		}
	}
}

LRESULT CALLBACK Hikari::Engine::MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_KEYDOWN:
		{
			m_Input->KeyDown((unsigned int)wParam);
			return 0;
		}
		case WM_KEYUP:
		{
			m_Input->KeyUp((unsigned int)wParam);
			return 0;
		}
		default:
		{
			return DefWindowProc(WindowHandle, message, wParam, lParam);
		}
	}
}

Hikari::Manager<Hikari::Object>* Hikari::Engine::objectManager(void)
{
	objectManagerMutex.lock();
	if(m_pObjectManager == NULL)
	{
		objectManagerMutex.unlock();
		throw new Exception("m_pObjectManager is not initialized in Engine::objectManager(void)", "NullPointerException");
	}
	objectManagerMutex.unlock();

	return m_pObjectManager;
}

void Hikari::Engine::objectManager(Hikari::Manager<Hikari::Object>* pObjectManager)
{
	if(pObjectManager == NULL)
	{
		throw new Exception("Can't set new ObjectManager to a NULL pointer in Engine::objectManager(Manager<Object>*)", "NullPointerException");
	}

	m_pObjectManager = pObjectManager;
}

Hikari::Manager<Hikari::Material>* Hikari::Engine::materialManager(void)
{
	materialManagerMutex.lock();
	if(m_pObjectManager == NULL)
	{
		materialManagerMutex.unlock();
		throw new Exception("m_pObjectManager is not initialized in Engine::materialManager(void)", "NullPointerException");
	}
	materialManagerMutex.unlock();

	return m_pMaterialManager;
}

void Hikari::Engine::materialManager(Hikari::Manager<Hikari::Material>* pMaterialManager)
{
	if(pMaterialManager == NULL)
	{
		throw new Exception("Can't set new MaterialManager to a NULL pointer in Engine::objectManager(Manager<Material>*)", "NullPointerException");
	}

	m_pMaterialManager = pMaterialManager;
}
