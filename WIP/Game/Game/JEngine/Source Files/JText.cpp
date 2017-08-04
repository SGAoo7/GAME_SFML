#include "../Header Files/JText.h"

JText::JText(JFont * _font)
{
	text.setFont(_font->GetFont());
}

JText::~JText()
{
}

sf::Text& JText::GetText()
{
	return text;
}

void JText::SetText(std::string _text)
{
	text.setString(_text);
}
