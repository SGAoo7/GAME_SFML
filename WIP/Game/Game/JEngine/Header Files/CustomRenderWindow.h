#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>

class CustomRenderWindow
{
public:
	CustomRenderWindow();
	~CustomRenderWindow();

	void BeginDraw();
	void EndDraw();

	bool isDone;
	sf::Vector2u GetWindowSize();
	sf::RenderWindow* GetWindow();

	void Draw(sf::Drawable& l_drawable);

	sf::RenderWindow window;
private:
	sf::Vector2u windowSize;

	///icon
	sf::String pathToIconImage = "../Assets/Icon/Icon.png";
};
