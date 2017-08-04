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
	void SetDistanceScore(int _amount);
	void SetHighscoreDistanceScore(int _amount);

	//getters
	int GetDistanceScore();
	int GetHighscoreDistanceScore();

private:
	int distanceScore;
	int highscoreDistanceScore;
};

