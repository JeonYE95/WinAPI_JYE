#pragma once
#include "SKEntity.h"
#include "Common.h"

namespace SK
{
	class GameObject;
	class Component : public Entity
	{
	public:
		friend class GameObject;
		Component(eComponentType type);
		Component() = delete;
		virtual ~Component();

		virtual void Tick() = 0;
		virtual void Render(HDC hdc);

		GameObject* GetOwner() { return mOwner; }

	private:
		const eComponentType mType;
		GameObject* mOwner;

	};

}