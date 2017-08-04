#pragma once

#include <SFML\Graphics.hpp>
#include "JFont.h"

class JText
{
public:
	JText(JFont* _font);
	~JText();

	sf::Text& GetText();
	void SetText(std::string _text);

private:
	sf::Text text;
};

