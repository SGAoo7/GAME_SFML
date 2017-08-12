#include "../Header Files/GameDataManager.h"

GameDataManager::GameDataManager()
{
	std::vector<std::string> lines = FileWriter::ReadFromFile("PlayerHighscore");

	if (lines.size() != 0)
		highscore = std::stoi(lines[0]);

	std::cout << highscore << std::endl;
}


GameDataManager::~GameDataManager()
{
	FileWriter::WriteToFile("PlayerHighscore", std::to_string(highscore), true);
}

void GameDataManager::SetHighscore(int _amount)
{
	highscore = _amount;
}

int GameDataManager::GetHighScore()
{
	return highscore;
}
