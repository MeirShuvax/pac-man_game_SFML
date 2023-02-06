#include "Resources.h"

Resources::Resources():
	m_images() , m_fonts(){}

Resources& Resources::resources()
{
	static auto resources = Resources();
	return resources;
}
//===============================================
LoadingImages& Resources::getImages()
{
	return m_images;
}
//===============================================
Font& Resources::getFonts()
{
	return m_fonts;
}
//===============================================
Sound& Resources::getSound()
{
	return m_sound;
}