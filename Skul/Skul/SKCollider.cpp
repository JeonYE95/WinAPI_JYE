#include "SKCollider.h"
#include "SKGameObject.h"
#include "SkApplication.h"

namespace SK
{
	Collider::Collider()
		: Component(eComponentType::Animator)
		, mOffset(Vector2::Zero)
		, mPos(Vector2::Zero)
		, mScale(Vector2::One)
	{
		mScale = Vector2(100.0f, 100.0f);
	}
	Collider::~Collider()
	{
	}
	void Collider::Tick()
	{
		GameObject* owner = GetOwner();
		mPos = owner->GetPos() + mOffset;
	}
	void Collider::Render(HDC hdc)
	{
		HPEN green = Application::GetInstance().GetPen(ePenColor::Green);
		Pen pen(hdc, green);

		HBRUSH tr = Application::GetInstance().GetBrush(eBrushColor::Transparent);
		Brush brush(hdc, tr);

		Rectangle(hdc, mPos.x , mPos.y, mPos.x + 40, mPos.y + 70);
	}
}