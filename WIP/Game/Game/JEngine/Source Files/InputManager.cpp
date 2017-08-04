#include "../Header Files/InputManager.h"
#include "../Header Files/Game.h"
#include "../Header Files/JButton.h"


InputManager::InputManager()
{
	keyPressed = false;
}


InputManager::~InputManager()
{
}

void InputManager::UpdatePollEvent()
{
	sf::Event _event;

	if (window->pollEvent(_event)) {
		if (_event.type == sf::Event::Closed) {
			game->GetWindow()->isDone = true;
		}
	}

	event = _event;

	UpdateBaicEvents();
}

void InputManager::UpdateBaicEvents()
{
	if (event.type == sf::Event::KeyReleased) {
		keyPressed = false;
	}
}

bool InputManager::KeyPressed(sf::Keyboard::Key _key)
{
	if (event.key.code == _key && event.type == sf::Event::KeyPressed && !keyPressed) {
		keyPressed = true;
		return true;
	}
	else {
		return false;
	}


}

bool InputManager::KeyDown(sf::Keyboard::Key _key)
{
	if (event.key.code == _key && event.type == sf::Event::KeyPressed) {
		keyPressed = true;
		return true;
	}
	else {
		return false;
	}
}

bool InputManager::KeyReleased(int _key)
{
	if (event.key.code == _key && event.type == sf::Event::KeyReleased) {
		return true;
	}
	else {
		return false;
	}
}

bool InputManager::OnMouseRelease(JButton* _button, sf::Mouse::Button _mouseButton)
{
	if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == _mouseButton) {
			if (_button->GetSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return true;
			}
		}
	}
	return false;
}

bool InputManager::OnMouse(JButton * _button, sf::Mouse::Button _mouseButton)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == _mouseButton) {
			if (_button->GetSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				return true;
			}
		}
	}
	return false;
}

void InputManager::SetGame(Game * _game)
{
	game = _game;
}

void InputManager::SetRenderWindow(sf::RenderWindow * _window)
{
	window = _window;
}
