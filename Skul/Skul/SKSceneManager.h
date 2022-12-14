#pragma once

#include "Common.h"


namespace SK
{
	class Scene;
	class SceneManager
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static void Release();

		static void ChangeScene(eSceneType type);

	private:
		static Scene* mScenes[(UINT)eSceneType::Max];
		static Scene* mPlayScene;

	};
}

