#include "../include/ExampleApplication.hpp"
#include "../../include/Engine.hpp"		// Hikari::Engine
#include "../../include/WrongArgumentException.hpp"
#include "../../include/WinAPIWindow.hpp"
#include "../../include/SimpleRenderer.hpp"
#include "../../include/Managers/Managers.hpp"
#include "../../include/Objects/Triangle.hpp"
#include <functional>

ExampleApplication::ExampleApplication() {}

void ExampleApplication::setup(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if(hInstance == NULL)
	{
		throw WrongArgumentException("niepoprawny argument hInstance(NULL)");
	}

	if(lpCmdLine == NULL)
	{
		throw WrongArgumentException("niepoprawny argument lpCmdLine (NULL)");
	}

	int options = SW_SHOWNORMAL|SW_SHOW|SW_HIDE|SW_MAXIMIZE|SW_MINIMIZE|SW_RESTORE|SW_SHOWMAXIMIZED|SW_SHOWMINIMIZED|SW_SHOWMINNOACTIVE|SW_SHOWNA|SW_SHOWNOACTIVATE;
	if(! (nCmdShow & options))
	{
		throw WrongArgumentException("niepoprawny parametr nCmdShow");
	}

	m_hInstance = hInstance;
	m_lpCmdLine = lpCmdLine;
	m_nCmdShow = nCmdShow;
}

void ExampleApplication::stopEngine(void)
{
	Hikari::Engine::stop();
}

/*
	to-do:
	
	- doda� tu komentarze w kodzie
	- doko�czy� komentowanie ca�o�ci (zwr�ci� uwag� przy pierwszych plikach na to, czy opisane s� wyj�tki rzucane przy z�ych parametrach/z�ych memberach)
	- doda� ustawianie DEBUG na 1 w Debug, a na 0 w Release
	- doda� zwalnianie poprzednich wska�nik�w przy ustawianiu nowych member�w, kt�re s� wska�nikami
	- doda� obs�ug� b��d�w inicjalizacji DirectXa (np. brak wsparcia)
	- Engine jako Singleton?
*/

void ExampleApplication::run(void)
{
	Hikari::Engine::initialize(m_hInstance, m_nCmdShow); // ale mo�na te� tak:
	/*
	Hikari::Engine::applicationInstanceHandle(m_hInstance);
	Hikari::Engine::windowShowFlags(m_nCmdShow);
	*/

	Hikari::Renderer* myRenderer = new Hikari::SimpleRenderer();
	Hikari::Engine::renderer(myRenderer);

	Hikari::Window* mainWindow = new Hikari::WinAPIWindow("Hikari::Engine application", 800, 600, 100, 100);
	Hikari::Engine::window(mainWindow);

	std::function<void(void)> escHandler = std::bind(&ExampleApplication::stopEngine, this);
	Hikari::Engine::input()->keyHandler(VK_ESCAPE, escHandler);	// ustaw escHandler jako procedur� obs�ugi przycisku Escape

	Hikari::ShaderProgram *pSimpleShader = new Hikari::ShaderProgram();
	pSimpleShader->setup(L"res/shaders/triangle.hlsl");
	pSimpleShader->entryPointNames("VShader", "PShader");
	pSimpleShader->compile();
	Hikari::HShader shaderHandle = Hikari::ShaderManager::add(pSimpleShader);

	Hikari::Object *pTriangle = new Hikari::Objects::Triangle(
		Hikari::Vector3D(0.0f, 0.5f, 0.0f),
		Hikari::Vector3D(0.45f, -0.5f, 0.0f),
		Hikari::Vector3D(-0.45f, -0.5f, 0.0f)
	);
	
	Hikari::Material *pMaterial = new Hikari::Material("triangle");
	pMaterial->shader(shaderHandle);
	Hikari::HMaterial hTriangleMaterial = Hikari::MaterialManager::add(pMaterial);
	pTriangle->material(hTriangleMaterial);

	Hikari::ObjectManager::add(pTriangle);

	Hikari::Engine::run();

	pTriangle->cleanup();
	delete pTriangle;
	delete pMaterial;
	pSimpleShader->cleanup();
	delete pSimpleShader;

	Hikari::Engine::cleanup();
}

ExampleApplication::~ExampleApplication() {}
