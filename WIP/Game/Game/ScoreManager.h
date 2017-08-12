#pragma once
class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	void AdjustScore(int _amount);
	void SetHighScore(int _amount);

	///getters;
	int GetScore();
	int GetHighscore();
private:
	int score;
	int highscore;
};

