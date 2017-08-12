#include "MainScene.h"
#include "JEngine\Header Files\Game.h"
#include "JEngine\Header Files\GameDataManager.h"



MainScene::MainScene()
{
	background = new JSprite(GetScene(), "../Assets/Art/Backgrounds/Background.png", false, false);
	endScreenBackground = new JSprite(GetScene(), "../Assets/Art/Backgrounds/EndBackground.png", false, false);
}

MainScene::~MainScene()
{
}

void MainScene::Start()
{
	Scene::Start();

	scoreText.SetText(std::to_string(0));
	activatedEndScreen = false;

	SetupArt();
	SetupUI();

	scoreManager.SetHighScore(game->GetGameDataManager()->GetHighScore());

	endScreenBackground->GetSprite().setColor(sf::Color(255, 255, 255, 0));
	scoreStaticText.GetText().setColor(sf::Color(255, 255, 255, 0));
	endScoreText.GetText().setColor(sf::Color(255, 255, 255, 0));
	highscoreStaticText.GetText().setColor(sf::Color(255, 255, 255, 0));
	highscoreText.GetText().setColor(sf::Color(255, 255, 255, 0));
	medalStaticText.GetText().setColor(sf::Color(255, 255, 255, 0));
}

void MainScene::Update(float _deltaTime)
{
	Scene::Update(_deltaTime);

	if (player.GetCrashedState() && !activatedEndScreen) {
		activatedEndScreen = true;
		ActivateEndScreen();
	}

	if (player.GetCrashedState())
		return;

	player.Update(_deltaTime);
	obstacleManager.Update(_deltaTime);

	for (int i = 0; i < obstacleManager.obstacles.size(); i++) {
		if (player.GetJSprite().GetSprite().getPosition().x >= obstacleManager.obstacles[i].upperTube->GetSprite().getPosition().x && !obstacleManager.obstacles[i].crossedObstacle) {
			obstacleManager.obstacles[i].crossedObstacle = true;
			scoreManager.AdjustScore(1);
			scoreText.SetText(std::to_string(scoreManager.GetScore()));
		}
	}

	if (background->GetSprite().getPosition().x <= animationBackgroundSwitchScale) {
		background->GetSprite().setPosition(0, background->GetSprite().getPosition().y);
	}
	else {
		background->GetSprite().setPosition(background->GetSprite().getPosition().x - 100 * _deltaTime, background->GetSprite().getPosition().y);
	}
}

void MainScene::SetupArt()
{
	background->GetSprite().setPosition(0, 0);
	animationBackgroundSwitchScale = background->GetTexture().getSize().x / 2;
	animationBackgroundSwitchScale = -animationBackgroundSwitchScale;

	sprites.insert(std::pair<int, JSprite*>(renderSpritesIndex, background));
	renderSpritesIndex++;

	player.GetJSprite().GetSprite().setScale(0.5f, 0.5f);
	player.GetJSprite().GetSprite().setPosition(200, 200);
	sprites.insert(std::pair<int, JSprite*>(renderSpritesIndex, &player.GetJSprite()));
	renderSpritesIndex++;

	for (int i = 0; i < obstacleManager.obstacles.size(); i++)
	{
		sprites.insert(std::pair<int, JSprite*>(renderSpritesIndex, obstacleManager.obstacles[i].lowerTube));
		renderSpritesIndex++;
		sprites.insert(std::pair<int, JSprite*>(renderSpritesIndex, obstacleManager.obstacles[i].upperTube));
		renderSpritesIndex++;
	}

	endScreenBackground->GetSprite().setScale(0.9f, 0.7f);
	endScreenBackground->GetSprite().setPosition(250, 150);
	sprites.insert(std::pair<int, JSprite*>(renderSpritesIndex, endScreenBackground));
	renderSpritesIndex++;
}

void MainScene::SetupUI()
{
	scoreText.GetText().setPosition(20, 10);
	texts.insert(std::pair<int, JText*>(0, &scoreText));

	medalStaticText.GetText().setString("MEDAL");
	medalStaticText.GetText().setPosition(260, 160);
	medalStaticText.GetText().setScale(0.5f, 0.5f);
	texts.insert(std::pair<int, JText*>(1, &medalStaticText));

	scoreStaticText.GetText().setString("SCORE");
	scoreStaticText.GetText().setPosition(410, 160);
	scoreStaticText.GetText().setScale(0.5f, 0.5f);
	texts.insert(std::pair<int, JText*>(2, &scoreStaticText));

	highscoreStaticText.GetText().setString("HIGHSCORE");
	highscoreStaticText.GetText().setPosition(367, 230);
	highscoreStaticText.GetText().setScale(0.5f, 0.5f);
	texts.insert(std::pair<int, JText*>(3, &highscoreStaticText));

	endScoreText.GetText().setString("0");
	endScoreText.GetText().setOrigin(endScoreText.GetText().getLocalBounds().width, 0);
	endScoreText.GetText().setPosition(465, 185);
	endScoreText.GetText().setScale(0.5f, 0.5f);
	texts.insert(std::pair<int, JText*>(4, &endScoreText));

	highscoreText.GetText().setString("0");
	highscoreText.GetText().setOrigin(highscoreText.GetText().getLocalBounds().width, 0);
	highscoreText.GetText().setPosition(465, 255);
	highscoreText.GetText().setScale(0.5f, 0.5f);
	texts.insert(std::pair<int, JText*>(5, &highscoreText));
}

void MainScene::ActivateEndScreen()
{
	endScreenBackground->GetSprite().setColor(sf::Color(255, 255, 255, 255));
	scoreStaticText.GetText().setColor(sf::Color(255, 255, 255, 255));
	endScoreText.GetText().setColor(sf::Color(255, 255, 255, 255));
	highscoreStaticText.GetText().setColor(sf::Color(255, 255, 255, 255));
	highscoreText.GetText().setColor(sf::Color(255, 255, 255, 255));
	medalStaticText.GetText().setColor(sf::Color(255, 255, 255, 255));

	endScoreText.GetText().setString(std::to_string(scoreManager.GetScore()));
	highscoreText.GetText().setString(std::to_string(scoreManager.GetHighscore()));

	int score = scoreManager.GetScore();

	game->GetGameDataManager()->SetHighscore(scoreManager.GetHighscore());

	if (score >= 10 && score < 20) {
		medalImage = new JSprite(GetScene(), medalBronzePath, true, false);
	}
	else if (score >= 20 && score < 30) {
		medalImage = new JSprite(GetScene(), medalSilverPath, true, false);
	}
	else if (score >= 30) {
		medalImage = new JSprite(GetScene(), medalGoldPath, true, false);
	}

	if (score >= 10) {
		medalImage->GetSprite().setScale(0.35f, 0.35f);
		medalImage->GetSprite().setPosition(267, 185);
		sprites.insert(std::pair<int, JSprite*>(renderSpritesIndex, medalImage));
		renderSpritesIndex++;
	}
	
}
