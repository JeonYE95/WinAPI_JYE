#pragma once
#include "SKComponent.h"

namespace SK
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Tick() override;

	private:

	};

}