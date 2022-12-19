#include "SKBGImageObject.h"
#include "SKResources.h"
#include "SKImage.h"

namespace SK
{
	BGImageObject::BGImageObject()
		: mImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);
	}
	BGImageObject::~BGImageObject()
	{
	}
	void BGImageObject::Initialize()
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"LogoBG", L"..\\Resources\\Image\\Title.bmp");
		}
	}
	void BGImageObject::Tick()
	{
		GameObject::Tick();
	}
	void BGImageObject::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y, mImage->GetDC()
			, 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255)
		);

		GameObject::Render(hdc);
		GameObject::Render(hdc);
	}
}