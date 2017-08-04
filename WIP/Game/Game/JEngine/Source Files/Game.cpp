#include "../Header Files/Game.h"

Game::Game()
{
	sceneManager.Init(this);
	input.SetRenderWindow(window.GetWindow());
	input.SetGame(this);
}


Game::~Game()
{
}

void Game::HandleInput() {
	input.UpdatePollEvent();
}

void Game::Update() {

	deltaTime = clock.restart().asSeconds();

	sceneManager.UpdateScene(deltaTime);
}

void Game::Render() {
	sceneManager.RenderScene();
}

GameDataManager * Game::GetGameDataManager()
{
	return &gameDataManager;
}

CustomRenderWindow* Game::GetWindow() {
	return &window;
}

SceneManager* Game::GetSceneManager() {
	return &sceneManager;
}

InputManager * Game::GetInputManager()
{
	return &input;
}
