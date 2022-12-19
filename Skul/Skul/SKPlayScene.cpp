#include "SKPlayScene.h"
#include "SKPlayer.h"
#include "SKSceneManager.h"
#include "SKInput.h"
#include "SKBGImageObject.h"


namespace SK
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		BGImageObject* bg = new BGImageObject();
		bg->SetImage(L"stagebg", L"stagebg.bmp");
		bg->Initialize();

		AddGameObject(bg);

		AddGameObject(new Player());
	}

	void PlayScene::Tick()
	{
		Scene::Tick();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}
	void PlayScene::Enter()
	{
	}
	void PlayScene::Exit()
	{
	}
}