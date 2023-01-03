#include "Image.h"
#include "SDL_image.h"
#include "SystemManager.h"

namespace System 
{
	Image::~Image()
	{
		SDL_DestroyTexture(tex);
	}

	void Image::LoadImage(std::string path)
	{
		SDL_Surface* img = IMG_Load(path.c_str());
		tex = SDL_CreateTextureFromSurface(SystemManager::GetPtr()->GetRenderer(), img);
		SDL_FreeSurface(img);
		SDL_QueryTexture(tex, NULL, NULL, &width, &height);
	}

	SDL_Texture* Image::GetTexture()
	{
		return tex;
	}

	int Image::GetWidth()
	{
		return width;
	}

	int Image::GetHeight()
	{
		return height;
	}
}