#pragma once
#include "SKEntity.h"
#include "Common.h"

namespace SK
{

	class Component : public Entity
	{
	public:
		Component(eComponentType type);
		Component() = delete;
		virtual ~Component();

		virtual void Tick() = 0;
		virtual void Render(HDC hdc);

	private:
		const eComponentType mType;


	};

}