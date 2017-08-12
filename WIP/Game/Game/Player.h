#pragma once

//must include
#include <SFML/Graphics.hpp>
#include "Jengine/Header Files/Animation.h"
#include "JEngine/Header Files/JSprite.h"
#include "JEngine/Header Files/Collider.h"
#include "JEngine/Header Files/JAudioSource.h"
#include "JEngine/Header Files/JButton.h"
#include "JEngine/Header Files/JText.h"
#include "JEngine/Header Files/JFont.h"
#include "JEngine/Header Files/InputManager.h"

class Scene;

class Player
{
public:
	Player(Scene* _scene);
	~Player();

	void Start();
	void Update(float _deltaTime);

	JSprite& GetJSprite();

	bool GetCrashedState();

private:
	InputManager* input;

	JSprite* plane;

	Animation* planeAnimation;

	float gravity;
	float groundHeight;
	float jumpSpeed;
	sf::Vector2f velocity;

	bool isJumping;

	bool crashed;
};

