#include "SkApplication.h"
#include "SKSceneManager.h"
#include "SKTime.h"
#include "SKInput.h"

namespace SK
{

	void Application::Initialize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();

		SceneManager::Tick();
		SceneManager::Render(mWindowData.hdc);

		Input::Render(mWindowData.hdc);
		Time::Render(mWindowData.hdc);
	}

	Application::Application()
	{
		mWindowData.clear();
	}

	Application::~Application()
	{
		SceneManager::Release();
		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
	}

}