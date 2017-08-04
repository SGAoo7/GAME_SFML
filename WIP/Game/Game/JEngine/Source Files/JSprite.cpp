#include "../Header Files/JSprite.h"
#include "../Header Files/Collider.h"
#include "../Header Files/Scene.h"

JSprite::JSprite(Scene* _scene, std::string _pathToSPrite, bool _isStatic, bool _isTrigger)
{
	texture.loadFromFile(_pathToSPrite);

	sprite.setTexture(texture);
	
	collider = new Collider(this, _scene, _isTrigger);
}

JSprite::~JSprite()
{
}

void JSprite::Move(float x, float y)
{
	collider->CheckPositionRelativeToObject();

	if (!collider->canMoveRight || !collider->canMoveLeft) {
		sprite.move(0, y);
	}
	else if (!collider->canMoveDown || !collider->canMoveUp) {
		sprite.move(x, 0);
	}
	else {
		sprite.move(x, y);
	}


	collider->canMoveUp = true;
	collider->canMoveDown = true;
	collider->canMoveLeft = true;
	collider->canMoveRight = true;
}

sf::Sprite& JSprite::GetSprite()
{
	return sprite;
}

sf::Texture& JSprite::GetTexture()
{
	return texture;
}

Collider& JSprite::GetCollider()
{
	return *collider;
}
