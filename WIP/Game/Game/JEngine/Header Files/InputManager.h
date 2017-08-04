#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Game;
class JButton;

class InputManager
{
public:
	InputManager();
	~InputManager();

	//update poll function
	void UpdatePollEvent();
	void UpdateBaicEvents();

	//key functions
	bool KeyPressed(sf::Keyboard::Key _key);
	bool KeyDown(sf::Keyboard::Key _key);
	bool KeyReleased(int _key);

	//mouse functions
	bool OnMouseRelease(JButton* _button, sf::Mouse::Button _mouseButton);
	bool OnMouse(JButton* _button, sf::Mouse::Button _mouseButton);

	//setters
	void SetGame(Game* _game);
	void SetRenderWindow(sf::RenderWindow* _window);

private:
	sf::Event event;

	Game* game;
	sf::RenderWindow* window;

	bool keyPressed;
};

