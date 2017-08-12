#pragma once

#include <iostream>
#include "FileWriter.h"

#include <string>
#include <vector>

class GameDataManager
{
public:
	GameDataManager();
	~GameDataManager();

	//setters
	void SetHighscore(int _amount);

	//getters
	int GetHighScore();

private:
	int highscore;
};

