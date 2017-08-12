#include "Obstacle.h"


Obstacle::Obstacle(Scene* _scene)
{
	upperTube = new JSprite(_scene->GetScene(), "../Assets/Art/Obstacles/rockUpper.png", false, true);
	upperTube->GetSprite().setScale(0.8f, 0.8f);
	lowerTube = new JSprite(_scene->GetScene(), "../Assets/Art/Obstacles/rockLower.png", false, true);
	lowerTube->GetSprite().setScale(0.8f, 0.8f);

	crossedObstacle = true;

	upperTube->GetSprite().setOrigin(upperTube->GetTexture().getSize().x / 2, upperTube->GetTexture().getSize().y);
	lowerTube->GetSprite().setOrigin(upperTube->GetTexture().getSize().x / 2, 0);
}

Obstacle::~Obstacle()
{

}
