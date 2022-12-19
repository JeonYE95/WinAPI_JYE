#pragma once

#define KEY_PRESSE(KEY) SK::Input::GetKeyState(KEY) == SK::eKeyState::PRESSED
#define KEY_DOWN(KEY) SK::Input::GetKeyState(KEY) == SK::eKeyState::DOWN
#define KEY_UP(KEY) SK::Input::GetKeyState(KEY) == SK::eKeyState::UP

enum class eSceneType
{
	Logo,
	Play,
	End,
	Max,
};

enum class ePenColor
{
	Red,
	Green,
	Blue,
	End,
};

enum class eBrushColor
{
	Transparent,
	Black,
	Gray, // 71, 71, 71
	White,
	End,
};

enum class eComponentType
{
	Animator,
	Collider,
	Sound,
	End,
};