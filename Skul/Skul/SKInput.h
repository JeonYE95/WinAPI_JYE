#pragma once

#include "Common.h"

namespace SK
{
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,

		ENTER, ESC, LSHIFT, LALT, LCTRL,
		SPACE, LEFT, RIGHT, UP, DOWN,
		LBTN, RBTN,

		End,
	};

	enum class eKeyState
	{
		DOWN,
		PRESSED,
		UP,
		NONE,
	};

	class Input
	{

	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static eKeyState GetKeyState(eKeyCode keyCode);

	private:
		static std::vector<Key> mKeys;

	};

}