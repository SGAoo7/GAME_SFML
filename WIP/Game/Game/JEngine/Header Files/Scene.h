#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include <string>
#include <map>

#include "InputManager.h"
#include "JSprite.h"

class Game;
class JSprite;
class JButton;
class JText;
class SceneManager;
class CustomRenderWindow;

class Scene
{
public:
	Scene();
	~Scene();

	//used to initialize scene
	void Init(Game* _game, int _sceneIndex);

	///start and update of scene
	virtual void Start();
	virtual void Update(float _deltaTime);

	void DestroyJSprite(JSprite* _jSprite);

	///getters
	Scene* GetScene();

public:
	///maps who needs to be drawn
	std::map<int, JSprite*> sprites;
	int renderSpritesIndex;

	std::map<int, JText*> texts;
	std::map<int, JButton*> buttons;

	//index of scene
	int sceneIndex;

	//time
	float deltaTime;

	///component pointers
	Game* game;

	SceneManager* sceneManager;
	CustomRenderWindow* window;
	Scene* currentScene;
	InputManager* input;
};

