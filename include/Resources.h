#pragma once
#include "LoadingImages.h"
#include "Font.h"
#include "Sound.h"

class Resources
{
public:
	
	static Resources& resources();
	Resources(const Resources&) = delete;
	void operator = (const Resources&) = delete;
	LoadingImages& getImages();
	Font& getFonts();
	Sound& getSound();


private:
	Resources();
	LoadingImages m_images;
	Font m_fonts;
	Sound m_sound;

};

