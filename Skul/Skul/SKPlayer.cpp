#include "SKPlayer.h"
#include "SKTime.h"
#include "SKInput.h"
#include "SKSceneManager.h"

namespace SK
{

	Player::Player()
		: mSpeed(1.0f)
	{
		SetPos({ 100.0f, 100.0f });
		SetScale({ 100.0f, 100.0f });
	}

	Player::~Player()
	{
	}

	void Player::Tick()
	{
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
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Rectangle(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);
	}

}