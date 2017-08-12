#include "../Header Files/SceneManager.h"
#include "../Header Files/Game.h"
#include "../Header Files/Scene.h"
#include "../Header Files/JSprite.h"
#include "../Header Files/JButton.h"
#include "../Header Files/JText.h"
#include "../Header Files/CustomRenderWindow.h"

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::Init(Game* _game)
{
	SetRenderWindow(_game->GetWindow());

	exampleScene.Init(_game, 0);
	mainScene.Init(_game, 1);

	SwitchScene(0);
}

void SceneManager::SwitchScene(int _index)
{

	exampleScene.~ExampleScene();
	new (&exampleScene) ExampleScene();

	mainScene.~MainScene();
	new (&mainScene) MainScene();

	currentScene = scenes[_index];
	currentSceneIndex = currentScene->sceneIndex;
	currentScene->Start();
}

void SceneManager::UpdateScene(float _deltaTime)
{
	currentScene->Update(_deltaTime);
}

void SceneManager::RenderScene()
{
	//clear
	costumRenderWindow->BeginDraw();

	//draw
	for (std::map<int, JSprite*>::iterator it = currentScene->sprites.begin(); it != currentScene->sprites.end(); ++it) {
		costumRenderWindow->Draw(it->second->GetSprite());
	}

	for (std::map<int, JText*>::iterator it = currentScene->texts.begin(); it != currentScene->texts.end(); ++it) {
		costumRenderWindow->Draw(it->second->GetText());
	}

	for (std::map<int, JButton*>::iterator it = currentScene->buttons.begin(); it != currentScene->buttons.end(); ++it) {
		costumRenderWindow->Draw(it->second->GetSprite());
	}

	//display
	costumRenderWindow->EndDraw();
}

void SceneManager::SetRenderWindow(CustomRenderWindow* _customRenderWindow)
{
	costumRenderWindow = _customRenderWindow;
}

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}
