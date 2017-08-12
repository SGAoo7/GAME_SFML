#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Scene;
class Collider;

class JSprite
{
public:
	JSprite(Scene* _scene, std::string _pathToSPrite, bool _isStatic, bool _isTrigger);
	~JSprite();

	void Move(float x, float y);

	///getters;
	sf::Sprite& GetSprite();
	sf::Texture& GetTexture();
	Collider& GetCollider();

	///setters;
	void SetFillScale(float x, float y);

private:
	sf::Sprite sprite;
	sf::Texture texture;

	Collider* collider;
};
