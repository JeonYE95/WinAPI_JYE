#pragma once

#define KEY_PRESSE(KEY) SK::Input::GetKeyState(KEY) == SK::eKeyState::PRESSED
#define KEY_DOWN(KEY) SK::Input::GetKeyState(KEY) == SK::eKeyState::DOWN
#define KEY_UP(KEY) SK::Input::GetKeyState(KEY) == SK::eKeyState::UP

enum class eSceneType
{
	Logo,
	Title,
	Play,
	End,
	Max,
};
