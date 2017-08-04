#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation(sf::Texture* _texture, sf::Vector2u _imageCount, float _switchTime);
	~Animation();

	void Update(int _row, float _deltaTime);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

