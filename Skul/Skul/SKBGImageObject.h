#pragma once
#include "SKGameObject.h"


namespace SK
{
	class Image;
	class BGImageObject : public GameObject
	{
	public:
		BGImageObject();
		~BGImageObject();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& filename);

	private:
		Image* mImage;
		std::wstring mImageName;

	};

}