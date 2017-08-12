#pragma once

//must include
#include <SFML/Graphics.hpp>
#include "JEngine/Header Files/Scene.h"
#include "Jengine/Header Files/Animation.h"
#include "JEngine/Header Files/JSprite.h"
#include "JEngine/Header Files/Collider.h"
#include "JEngine/Header Files/JAudioSource.h"
#include "JEngine/Header Files/JButton.h"
#include "JEngine/Header Files/JText.h"
#include "JEngine/Header Files/JFont.h"

#include "Player.h"
#include "ObstacleManager.h"
#include "ScoreManager.h"

#include <iostream>

class MainScene : public Scene
{
public:
	MainScene();
	~MainScene();

	void Start();
	void Update(float _deltaTime);

	void SetupArt();
	void SetupUI();

	void ActivateEndScreen();

private:
	JSprite* background;
	float animationBackgroundSwitchScale;

	Player player = Player(this);
	ObstacleManager obstacleManager = ObstacleManager(this);

	ScoreManager scoreManager;

	JFont font = JFont("../Assets/Fonts/Font.ttf");
	JText scoreText = JText(&font);

	bool activatedEndScreen;
	JSprite* endScreenBackground;

	JText medalStaticText = JText(&font);
	JSprite* medalImage;
	std::string medalBronzePath = "../Assets/Art/Medals/MedalBronze.png";
	std::string medalSilverPath = "../Assets/Art/Medals/MedalSilver.png";
	std::string medalGoldPath = "../Assets/Art/Medals/MedalGold.png";


	JText scoreStaticText = JText(&font);
	JText endScoreText = JText(&font);
	
	JText highscoreStaticText = JText(&font);
	JText highscoreText = JText(&font);
};

