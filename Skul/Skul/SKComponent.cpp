#include "SKComponent.h"


namespace SK
{
	Component::Component(eComponentType type)
		: mType(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Render(HDC hdc)
	{
	}

}