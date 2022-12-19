#include "SKPlayer.h"
#include "SKTime.h"
#include "SKSceneManager.h"
#include "SKInput.h"
#include "SKScene.h"
#include "SKImage.h"
#include "SKResources.h"
#include "SKAnimator.h"
#include "SKCollider.h"

namespace SK
{

	Player::Player()
		: mSpeed(1.0f)
	{
		SetPos({ 100.0f, 100.0f });
		SetScale({ 2.0f, 2.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\R_Idle_0.bmp");
		}

		AddComponent(new Animator());
		AddComponent(new Collider());
	}

	Player::~Player()
	{
	}

	void Player::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();
		if (KEY_PRESSE(eKeyCode::UP))
		{
			pos.y -= 120.0f * Time::DeltaTime();
		}
		if (KEY_PRESSE(eKeyCode::DOWN))
		{
			pos.y += 120.0f * Time::DeltaTime();
		}
		if (KEY_PRESSE(eKeyCode::LEFT))
		{ 
			pos.x -= 120.01f * Time::DeltaTime();
		}
		if (KEY_PRESSE(eKeyCode::RIGHT))
		{
			pos.x += 120.0f * Time::DeltaTime();
		}

		if (KEY_PRESSE(eKeyCode::X))
		{

		}
		SetPos(pos);
	}

	void Player::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(153, 204, 255));
		Brush brush(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		Pen pen(hdc, redPen);

		Vector2 pos = GetPos();
		Vector2 scale = GetScale();


		//BitBlt(hdc, pos.x, pos.y
		//	  , mImage->GetWidth(), mImage->GetHeight(), mImage->GetDC()
		//	  , 0, 0, SRCCOPY);

		/*pos = Vector2::Zero;*/

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() / scale.x);
		finalPos.y = (pos.y - mImage->GetHeight());

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y, mImage->GetDC()
			          , 0, 0, mImage->GetWidth(), mImage->GetHeight()
			          , RGB(255, 0, 255)
		              );

		GameObject::Render(hdc);
	}

}