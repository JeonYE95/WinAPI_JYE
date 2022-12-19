#include "SkApplication.h"
#include "SKSceneManager.h"
#include "SKTime.h"
#include "SKInput.h"
#include "SKResources.h"

namespace SK
{

	void Application::Initialize(WindowData data)
	{
		InitializeWindow(data);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();

		Brush brush(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::Gray]);

		Rectangle(mWindowData.backBuffer, 
			      -1, -1, mWindowData.width + 1, mWindowData.height + 1);

		SceneManager::Tick();
		SceneManager::Render(mWindowData.backBuffer);

		Input::Render(mWindowData.backBuffer);
		Time::Render(mWindowData.backBuffer);

		BitBlt(mWindowData.hdc, 0, 0, mWindowData.width, mWindowData.height,
			   mWindowData.backBuffer, 0, 0, SRCCOPY);
	}

	Application::Application()
	{
		mWindowData.clear();
	}

	Application::~Application()
	{
		SceneManager::Release();
		Resources::Release();

		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
		ReleaseDC(mWindowData.hWnd, mWindowData.backBuffer);
	}

	void Application::InitializeWindow(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		RECT rect = { 0, 0, mWindowData.width, mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mWindowData.hWnd,
			nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top,
			0);

		ShowWindow(mWindowData.hWnd, true);

		mWindowData.backTexture = CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);

		mWindowData.backBuffer = CreateCompatibleDC(mWindowData.hdc);
		HBITMAP defaultBitmap = (HBITMAP)SelectObject(mWindowData.backBuffer, mWindowData.backTexture);

		DeleteObject(defaultBitmap);

		mPens[(UINT)ePenColor::Red] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		mPens[(UINT)ePenColor::Green] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		mPens[(UINT)ePenColor::Blue] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

		mBrushes[(UINT)eBrushColor::Transparent] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		mBrushes[(UINT)eBrushColor::Black] = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mBrushes[(UINT)eBrushColor::Gray] = CreateSolidBrush(RGB(71, 71, 71));
		mBrushes[(UINT)eBrushColor::White] = (HBRUSH)GetStockObject(WHITE_BRUSH);
	}
}