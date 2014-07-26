#include "../include/ExampleApplication.hpp"
#include "../../include/Engine.hpp"		// Hikari::Engine
#include "../../include/WrongArgumentException.hpp"
#include "../../include/WinAPIWindow.hpp"
#include "../../include/SimpleRenderer.hpp"
#include "../../include/Managers/Managers.hpp"
#include "../../include/Objects/Triangle.hpp"
#include "../../include/Textures/Texture2D.hpp"
#include <functional>

ExampleApplication::ExampleApplication() {}

void ExampleApplication::setup(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if(hInstance == nullptr)
	{
		throw WrongArgumentException("niepoprawny argument hInstance(nullptr)");
	}

	if(lpCmdLine == nullptr)
	{
		throw WrongArgumentException("niepoprawny argument lpCmdLine (nullptr)");
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
	
	- dodaæ tu komentarze w kodzie
	- dokoñczyæ komentowanie ca³oœci (zwróciæ uwagê przy pierwszych plikach na to, czy opisane s¹ wyj¹tki rzucane przy z³ych parametrach/z³ych memberach)
	- dodaæ ustawianie DEBUG na 1 w Debug, a na 0 w Release
	- dodaæ zwalnianie poprzednich wskaŸników przy ustawianiu nowych memberów, które s¹ wskaŸnikami
	- dodaæ obs³ugê b³êdów inicjalizacji DirectXa (np. brak wsparcia)
	- Engine jako Singleton?
*/

void ExampleApplication::run(void)
{
	Hikari::Engine::initialize(m_hInstance, m_nCmdShow); // ale mo¿na te¿ tak:
	/*
	Hikari::Engine::applicationInstanceHandle(m_hInstance);
	Hikari::Engine::windowShowFlags(m_nCmdShow);
	*/

	Hikari::Renderer* myRenderer = new Hikari::SimpleRenderer();
	Hikari::Engine::renderer(myRenderer);

	Hikari::Window* mainWindow = new Hikari::WinAPIWindow("Hikari::Engine application", 800, 600, 100, 100);
	Hikari::Engine::window(mainWindow);

	std::function<void(void)> escHandler = std::bind(&ExampleApplication::stopEngine, this);
	Hikari::Engine::input()->keyHandler(VK_ESCAPE, escHandler);	// ustaw escHandler jako procedurê obs³ugi przycisku Escape

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
	
	Hikari::Texture2D* pTexture = new Hikari::Texture2D();

	try
	{
		const char *path = "res/textures/black_marble.jpg";
		pTexture->load(path);	// b³¹d 1291 DevILa
	}
	catch(Exception& e)
	{
		MessageBox(NULL, e.message(), e.type(), MB_OK);
		delete [] e.message();
	}

	Hikari::Material *pMaterial = new Hikari::Material("triangle");
	pMaterial->shader(shaderHandle);
	Hikari::HTexture hTexture = Hikari::TextureManager::add(pTexture);
	pMaterial->diffuseMap(hTexture);

	Hikari::HMaterial hTriangleMaterial = Hikari::MaterialManager::add(pMaterial);
	pTriangle->material(hTriangleMaterial);

	Hikari::ObjectManager::add(pTriangle);

	Hikari::Engine::run();

	pTriangle->cleanup();
	delete pTriangle;
	pTriangle = nullptr;
	delete pMaterial;
	pMaterial = nullptr;
	pSimpleShader->cleanup();
	delete pSimpleShader;
	pSimpleShader = nullptr;
	delete pTexture;
	pTexture = nullptr;

	Hikari::Engine::cleanup();
}

ExampleApplication::~ExampleApplication() {}
