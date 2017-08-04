#include "ExampleScene.h"



ExampleScene::ExampleScene()
{
	background = new JSprite(GetScene(), "../Assets/Menu/background.png", true, false);
	plane = new JSprite(GetScene(), "../Assets/Art/Plane/Yellow/plane.png", true, false);
}


ExampleScene::~ExampleScene()
{
}

//Runs when scene starts;
void ExampleScene::Start()
{
	Scene::Start();

	SetupArt();
	SetupUI();
	
	std::cout << "Running start function of the example scene" << std::endl;
}

//Runs continuously when scene is active;
void ExampleScene::Update(float _deltaTime)
{
	Scene::Update(_deltaTime);
}

void ExampleScene::SetupArt()
{
	background->GetSprite().setPosition(0, 0);
	sprites.insert(std::pair<int, JSprite*>(0, background));

	plane->GetSprite().setScale(0.5f, 0.5f);
	plane->GetSprite().setPosition(200, 200);
	plane->GetSprite().setTextureRect(sf::IntRect(0, 0, plane->GetTexture().getSize().x / 3, plane->GetTexture().getSize().y));
	sprites.insert(std::pair<int, JSprite*>(1, plane));
}

void ExampleScene::SetupUI()
{	
	startText.SetText("Press space to jump");
	startText.GetText().setPosition(70, 270);
	startText.GetText().setColor(sf::Color::Yellow);
	texts.insert(std::pair<int, JText*>(0, &startText));
}
