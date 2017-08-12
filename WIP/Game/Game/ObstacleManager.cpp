#include "ObstacleManager.h"

ObstacleManager::ObstacleManager(Scene * _scene)
{

	for (int i = 0; i < 5; i++) {
		Obstacle obstacle = Obstacle(_scene);
		obstacles.push_back(obstacle);
	}
	for (int i = 0; i < obstacles.size(); i++) {
		obstacles[i].lowerTube->GetSprite().setPosition(-100.0f, obstacles[i].lowerTube->GetSprite().getPosition().y);
	}
	obstacleMoverIndex = 0;
	spawnSwitch = 2;
	spawnCounter = spawnSwitch;
}

ObstacleManager::~ObstacleManager()
{
}

void ObstacleManager::Update(float _deltaTime)
{
	for (int i = 0; i < obstacles.size(); i++) {
		obstacles[i].lowerTube->GetSprite().setPosition(obstacles[i].lowerTube->GetSprite().getPosition().x - 150 * _deltaTime, obstacles[i].lowerTube->GetSprite().getPosition().y);
		obstacles[i].upperTube->GetSprite().setPosition(obstacles[i].upperTube->GetSprite().getPosition().x - 150 * _deltaTime, obstacles[i].upperTube->GetSprite().getPosition().y);
	}

	spawnCounter += _deltaTime;
	
	if (spawnCounter >= spawnSwitch) {
		SetNewPosition(&obstacles[obstacleMoverIndex]);
		obstacles[obstacleMoverIndex].crossedObstacle = false;
		obstacleMoverIndex++;
		spawnCounter = 0;

		if (obstacleMoverIndex >= obstacles.size()) {
			obstacleMoverIndex = 0;
		}
	}
}

void ObstacleManager::SetNewPosition(Obstacle * _obstacle)
{
	float xValue = 800;

	int minYValue = 20;
	int maxYValue = 410 - _obstacle->lowerTube->GetTexture().getSize().y;

	float rYValue = rand() % (maxYValue - minYValue + 1) + minYValue;

	_obstacle->upperTube->GetSprite().setPosition(xValue, rYValue);
	_obstacle->lowerTube->GetSprite().setPosition(xValue, rYValue + 200);
}
