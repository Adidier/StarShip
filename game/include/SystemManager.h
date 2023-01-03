#pragma once
#include "SDL.h"
#include "Image.h"
#include <map>
#include "Vector2.h"

namespace System {
	class SystemManager
	{
	public:
		bool InitWindow();
		int Input(std::map<char, bool> &keys);
		void ClearScreen();
		void Draw(Image* img, Vector2 p);
		void Exit();
		static SystemManager* GetPtr();
		SDL_Renderer* GetRenderer();
		void RenderScreen();
		int GetScreenWidth();
		int GetScreenHeight();

	private:
		int screenWidth;
		int screenHeight;
		bool fullScreen;
		SystemManager();
		static SystemManager* ptr;
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
	};
}
