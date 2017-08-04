#pragma once

#include <iostream>
#include <list>
#include <map>

class Game;
class Scene;
class CustomRenderWindow;

//include all your scene headers here;
#include "../../ExampleScene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init(Game* _game);

	std::map<int, Scene*> scenes;

	void SwitchScene(int _index);
	void UpdateScene(float _deltaTime);
	void RenderScene();

	//setters
	void SetRenderWindow(CustomRenderWindow* _customRenderWindow);

	//getters
	Scene* GetCurrentScene();

private:
	Scene* currentScene;
	int currentSceneIndex;

	//pointers to classes
	CustomRenderWindow* costumRenderWindow;

	//all your scenes
	ExampleScene exampleScene;
};

