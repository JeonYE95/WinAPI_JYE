#include "SKGameObject.h"

namespace SK
{
	GameObject::GameObject()
		: mPos{ 0.0f, 0.0f }
		, mScale{ 1.0f, 1.0f }
	{
	}

	GameObject::~GameObject()
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;

			delete component;
			component = nullptr;
		}
	}

	void GameObject::Initialize()
	{

	}

	void GameObject::Tick()
	{
		for ( Component* component : mComponents)
		{
			if (component ==nullptr)
				continue;

			component->Tick();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;

			component->Render(hdc);
		}
	}
	void GameObject::AddComponent(Component* component)
	{
		mComponents.push_back(component);
	}
}