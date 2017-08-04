#include "../Header Files/GameDataManager.h"

GameDataManager::GameDataManager()
{
	std::vector<std::string> lines = FileWriter::ReadFromFile("PlayerHighscore");

	if (lines.size() != 0)
		highscoreDistanceScore = std::stoi(lines[0]);

	distanceScore = 0;
}


GameDataManager::~GameDataManager()
{

	FileWriter::WriteToFile("PlayerHighscore", std::to_string(highscoreDistanceScore), true);


}

void GameDataManager::SetDistanceScore(int _amount)
{
	distanceScore = _amount;

	if (_amount > highscoreDistanceScore) {
		SetHighscoreDistanceScore(_amount);
	}
}

void GameDataManager::SetHighscoreDistanceScore(int _amount)
{
	highscoreDistanceScore = _amount;
}

int GameDataManager::GetDistanceScore()
{
	return distanceScore;
}

int GameDataManager::GetHighscoreDistanceScore()
{
	return highscoreDistanceScore;
}
