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
		virtual void Render(HDC hdc) override;

		void SetScale(Vector2 scale) { scale = mScale; }
		void SetPos(Vector2 pos) { mPos = pos; }
		void SetOffset(Vector2 pos) { mOffset = pos; }

	private:
		Vector2 mOffset;
		Vector2 mPos;
		Vector2 mScale;
	};

}