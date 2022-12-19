#pragma once
#include "Common.h"


namespace SK
{
	// ���� ���α׷�
	class Application
	{
	public:
		static Application& GetInstance()
		{
			static Application mInstance;
			return mInstance;
		}

		void Initialize(WindowData data);
		void Tick();

		WindowData GetWindowData() { return mWindowData; }

	private:
		Application();
		~Application();

		void InitializeWindow(WindowData data);

	private:
		WindowData mWindowData;
		HPEN mPens[(UINT)ePenColor::End];
		HBRUSH mBrushes[(UINT)eBrushColor::End];
	};
}

