#include "SKComponent.h"


namespace SK
{
	Component::Component(eComponentType type)
		: mType(type)
		, mOwner(nullptr)
	{
	}

	Component::~Component()
	{
	}

	void Component::Render(HDC hdc)
	{
	}

}