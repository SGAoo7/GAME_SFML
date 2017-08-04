#include "../Header Files/Collider.h"



Collider::Collider(JSprite* _sprite, Scene* _scene, bool _isTrigger) : isTrigger(_isTrigger), thisInteractable(_sprite)
{
	canMoveUp = true;
	canMoveDown = true;
	canMoveLeft = true;
	canMoveRight = true;

	scene = _scene;
}


Collider::~Collider()
{
}

JSprite* Collider::Collide()
{
	SetJSprites();

	for (std::map<int, JSprite*>::iterator it = collidableObjects.begin(); it != collidableObjects.end(); ++it) {
		if (thisInteractable->GetSprite().getGlobalBounds().intersects(it->second->GetSprite().getGlobalBounds())) {
			if (!it->second->GetCollider().isTrigger) {
				return nullptr;
			}
			else {
				return it->second;
			}
		}
	}

	return nullptr;
}

void Collider::CheckPositionRelativeToObject()
{
	SetJSprites();

	for (std::map<int, JSprite*>::iterator it = collidableObjects.begin(); it != collidableObjects.end(); ++it) {
		if (it->second->GetCollider().isTrigger)
			return;

		if (thisInteractable->GetSprite().getGlobalBounds().intersects(it->second->GetSprite().getGlobalBounds())) {

			float rightSideOfThisInteractable = thisInteractable->GetSprite().getPosition().x + (thisInteractable->GetTexture().getSize().x * 2);
			float leftSideOfOtherInteratable = it->second->GetSprite().getPosition().x;

			float rightSideOfOtherInteratable = it->second->GetSprite().getPosition().x + (it->second->GetTexture().getSize().x * 2);
			float leftSideOfThisInteratable = thisInteractable->GetSprite().getPosition().x;

			float topOfThisInteractable = thisInteractable->GetSprite().getPosition().y;
			float bottomOfOtherInteractable = it->second->GetSprite().getPosition().y + (it->second->GetTexture().getSize().y * 2);

			float topOfOtherInteractable = it->second->GetSprite().getPosition().y;
			float bottomOfThisInteractable = thisInteractable->GetSprite().getPosition().y + (thisInteractable->GetTexture().getSize().y * 2);

			//left side;
			//first check is position is greater then x position of iterator;
			//then check if position is also smaller then the half of the iterator image;
			if (rightSideOfThisInteractable >= leftSideOfOtherInteratable && rightSideOfThisInteractable <= leftSideOfOtherInteratable + it->second->GetTexture().getSize().x) {
				thisInteractable->GetSprite().setPosition(sf::Vector2f(it->second->GetSprite().getPosition().x - (thisInteractable->GetTexture().getSize().x * 2), thisInteractable->GetSprite().getPosition().y));
				canMoveRight = false;
			}

			//right side;
			if (leftSideOfThisInteratable <= rightSideOfOtherInteratable  && leftSideOfThisInteratable >= leftSideOfOtherInteratable + it->second->GetTexture().getSize().x) {
				thisInteractable->GetSprite().setPosition(sf::Vector2f(it->second->GetSprite().getPosition().x + (thisInteractable->GetTexture().getSize().x * 2), thisInteractable->GetSprite().getPosition().y));
				canMoveLeft = false;
			}

			//bottom;
			if (topOfThisInteractable <= bottomOfOtherInteractable && topOfThisInteractable >= topOfOtherInteractable + it->second->GetTexture().getSize().y) {
				thisInteractable->GetSprite().setPosition(sf::Vector2f(thisInteractable->GetSprite().getPosition().x, bottomOfOtherInteractable));
				canMoveUp = false;
			}

			//top;
			if (bottomOfOtherInteractable >= topOfOtherInteractable && bottomOfThisInteractable <= topOfOtherInteractable + it->second->GetTexture().getSize().y) {
				thisInteractable->GetSprite().setPosition(sf::Vector2f(thisInteractable->GetSprite().getPosition().x, topOfOtherInteractable - (it->second->GetTexture().getSize().y * 2)));
				canMoveDown = false;
			}
		}		
	}
}

void Collider::SetJSprites()
{
	collidableObjects.clear();
	collidableObjects = scene->sprites;

	for (std::map<int, JSprite*>::iterator it = scene->sprites.begin(); it != scene->sprites.end(); ++it) {
		if (it->second == thisInteractable) {
			collidableObjects.erase(it->first);
		}
	}
}

JSprite* Collider::GetThisInteractable()
{
	return thisInteractable;
}

bool Collider::IsTrigger()
{
	return isTrigger;
}
