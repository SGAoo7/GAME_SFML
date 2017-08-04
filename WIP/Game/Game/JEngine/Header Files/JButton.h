#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Scene.h"
#include "InputManager.h"

class JButton
{
public:
	JButton(Scene* _scene, std::string _buttonImagePath);
	~JButton();

	bool OnClick(sf::Mouse::Button _mouseButton);

	void SetPressedImage(std::string _buttonImagePath);

	///getters;
	sf::Sprite& GetSprite();
	
private:
	sf::Sprite button;
	sf::Texture buttonTexture;
	sf::Texture buttonPressedTexture;

	bool hasPressedTexture = false;

	Scene* scene;
	InputManager* input;
};

