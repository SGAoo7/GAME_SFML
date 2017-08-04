#pragma once

#include <SFML\Graphics.hpp>
#include "CustomRenderWindow.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "GameDataManager.h"

class Game
{
public:
	Game();
	~Game();

	//main functions for game
	void HandleInput();
	void Update();
	void Render();

	//getters
	GameDataManager* GetGameDataManager();

	CustomRenderWindow* GetWindow();
	SceneManager* GetSceneManager();
	InputManager* GetInputManager();

	//time
	float deltaTime;

private:
	//time
	sf::Clock clock;

	//data container
	GameDataManager gameDataManager;

	//main components
	CustomRenderWindow window;
	SceneManager sceneManager;
	InputManager input;
};

