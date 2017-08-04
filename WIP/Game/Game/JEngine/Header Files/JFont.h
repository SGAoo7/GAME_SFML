#pragma once

#include <SFML\Graphics.hpp>

class JFont
{
public:
	JFont(std::string _pathToFont);
	~JFont();

	sf::Font& GetFont();

private:
	sf::Font font;
};

