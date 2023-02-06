#include "Font.h"

Font::Font()
{
	m_fontAriel.loadFromFile("C:/Windows/Fonts/COOPBL.TTF");
}
//===============================================
sf::Font& Font::getFontAriel()
{
	return m_fontAriel;
}