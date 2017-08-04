#include "../Header Files/JFont.h"



JFont::JFont(std::string _pathToFont)
{
	font.loadFromFile(_pathToFont);
}


JFont::~JFont()
{
}

sf::Font& JFont::GetFont()
{
	return font;
}
