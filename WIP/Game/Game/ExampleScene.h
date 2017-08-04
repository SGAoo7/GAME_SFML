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

#include <iostream>

class ExampleScene : public Scene
{
public:
	ExampleScene();
	~ExampleScene();

	void Start();
	void Update(float _deltaTime);

	void SetupArt();
	void SetupUI();

private:
	JSprite* background;
	JSprite* plane;

	JFont font = JFont("../Assets/Fonts/Font.ttf");
	JText startText = JText(&font);
};

