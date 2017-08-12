#include "../Header Files/Scene.h"
#include "../Header Files/SceneManager.h"
#include "../Header Files/CustomRenderWindow.h"
#include "../Header Files/Game.h"

Scene::Scene()
{
	currentScene = this;
	renderSpritesIndex = 0;
}


Scene::~Scene()
{
}

void Scene::Init(Game* _game, int _sceneIndex)
{
	//set scene index
	sceneIndex = _sceneIndex;

	//set references
	game = _game;
	sceneManager = _game->GetSceneManager();
	window = _game->GetWindow();
	input = _game->GetInputManager();

	//insert in scenemanager map as scene
	sceneManager->scenes.insert(std::pair<int, Scene*>(sceneIndex, this));
}

void Scene::Start()
{
}

void Scene::Update(float _deltaTime)
{
	this->deltaTime = _deltaTime;
}

void Scene::DestroyJSprite(JSprite * _jSprite)
{
	for (std::map<int, JSprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
		if (it->second == _jSprite) {
			it = sprites.erase(it);
			break;
		}
	}
}

Scene* Scene::GetScene()
{
	return this;
}
