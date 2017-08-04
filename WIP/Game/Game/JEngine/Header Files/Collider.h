#pragma once

#include <SFML\Graphics.hpp>
#include <map>
#include "Scene.h"

class JSprite;
class Collider
{
public:
	Collider(JSprite* _sprite, Scene* _scene, bool _isTrigger);
	~Collider();

	JSprite* Collide();
	void CheckPositionRelativeToObject();
	void SetJSprites();

	JSprite* GetThisInteractable();
	bool IsTrigger();
public:
	bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
	int moveDirection; // 1 = up, 2 = down, 3 = right, 4 is left, 0 is none;

private:
	JSprite* thisInteractable;
	bool isTrigger;
	
	std::map<int, JSprite*> collidableObjects;

	Scene* scene;
};

