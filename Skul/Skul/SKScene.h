#pragma once
#include "Common.h"
#include "SKEntity.h"


namespace SK
{
	class GameObject;
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* object);

	private:
		std::vector<GameObject*> mObjects;
	};

}
