#include "SKScene.h"
#include "SKGameObject.h"
#include "SKPlayer.h"

namespace SK
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
		for (size_t i = 0; i < mObjects.size(); i++)
		{
			delete mObjects[i];
			mObjects[i] = nullptr;
		}
	}

	void Scene::Initialize()
	{
		for (size_t i = 0; i < mObjects.size(); i++)
		{
			mObjects[i]->Initialize();
		}
	}

	void Scene::Tick()
	{
		for (size_t i = 0; i < mObjects.size(); i++)
		{
			mObjects[i]->Tick();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (size_t i = 0; i < mObjects.size(); i++)
		{
			mObjects[i]->Render(hdc);
		}
	}

	void Scene::Enter()
	{
	}

	void Scene::Exit()
	{
	}

	void Scene::AddGameObject(GameObject* object)
	{
		if (object == nullptr)
			return;

		mObjects.push_back(object);
	}
}