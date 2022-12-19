#pragma once
#include "SKComponent.h"

namespace SK
{

	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		virtual void Tick() override;

	private:

	};

}