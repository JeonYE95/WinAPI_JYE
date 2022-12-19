#include "SKLogoScene.h"
#include "SKPlayer.h"
#include "SKInput.h"
#include "SKSceneManager.h"
#include "SKBGImageObject.h"

namespace SK
{
	LogoScene::LogoScene()
	{
	}

	LogoScene::~LogoScene()
	{
	}

	void LogoScene::Initialize()
	{
		BGImageObject* bg = new BGImageObject();
		bg->Initialize();

		AddGameObject(bg);

	}

	void LogoScene::Tick()
	{
		Scene::Tick();

		if (KEY_PRESSE(eKeyCode::ENTER))
		{
			SceneManager::ChangeScene(eSceneType::Play);
		}
	}

	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Logo Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}
	void LogoScene::Enter()
	{
	}
	void LogoScene::Exit()
	{
	}
}