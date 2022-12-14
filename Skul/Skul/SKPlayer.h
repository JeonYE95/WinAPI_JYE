#pragma once
#include "SKGameObject.h"

namespace SK
{
	class Image;
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		float mSpeed;
		Image* mImage;
	};
}