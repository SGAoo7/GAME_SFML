#include "ScoreManager.h"



ScoreManager::ScoreManager()
{
	score = 0;
}


ScoreManager::~ScoreManager()
{
}

void ScoreManager::AdjustScore(int _amount)
{
	score = score + _amount;

	if (score > highscore)
		SetHighScore(score);
}

void ScoreManager::SetHighScore(int _amount)
{
	highscore = _amount;
}

int ScoreManager::GetScore()
{
	return score;
}

int ScoreManager::GetHighscore()
{
	return highscore;
}
