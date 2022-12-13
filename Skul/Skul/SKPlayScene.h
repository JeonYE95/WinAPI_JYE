#pragma once
#include "SKScene.h"

namespace SK
{

	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

	private:

	};

}