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
#include "Obstacle.h"

#include <iostream>
#include <list>

class Scene;

class ObstacleManager
{
public:
	ObstacleManager(Scene* _scene);
	~ObstacleManager();

	void Update(float _deltaTime);
	void SetNewPosition(Obstacle* _obstacle);

public:
	std::vector<Obstacle> obstacles;
	int obstacleMoverIndex;

	float spawnCounter;
	int spawnSwitch;
};

