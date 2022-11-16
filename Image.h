#pragma once
#include "SDL.h"
#include <string>

namespace System {
	class Image
	{
	private:
		int width;
		int height;
		SDL_Texture* tex;
	public:
		void LoadImage(std::string path);
		SDL_Texture* GetTexture();

		int GetWidth();
		int GetHeight();
	};
}

