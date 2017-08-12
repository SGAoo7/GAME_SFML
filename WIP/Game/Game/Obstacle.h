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

class Obstacle
{
public:
	Obstacle(Scene* _scene);
	~Obstacle();

	JSprite* upperTube;
	JSprite* lowerTube;

	bool crossedObstacle;
};

