#include "SKInput.h"


namespace SK
{
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',

		VK_RETURN, VK_ESCAPE, VK_LSHIFT, VK_LMENU, VK_LCONTROL,
		VK_SPACE, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_RBUTTON,
	};

	std::vector<Input::Key> Input::mKeys;

    void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key;
			key.keyCode = (eKeyCode)i;
			key.state = eKeyState::NONE;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}
	void Input::Tick()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::End; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::PRESSED;
				else
					mKeys[i].state = eKeyState::DOWN;
				
				mKeys[i].bPressed = true;
			}
			else
			{
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::UP;
				else
					mKeys[i].state = eKeyState::NONE;

				mKeys[i].bPressed = false;
			}
		}
	}
	void Input::Render(HDC hdc)
	{

	}
	eKeyState Input::GetKeyState(eKeyCode keyCode)
	{
		return mKeys[(UINT)keyCode].state;
	}
}