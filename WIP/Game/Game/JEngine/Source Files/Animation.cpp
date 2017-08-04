#include "../Header Files/Animation.h"



Animation::Animation(sf::Texture* _texture, sf::Vector2u _imageCount, float _switchTime) : imageCount(_imageCount), switchTime(_switchTime)
{
	totalTime = 0;
	currentImage.x = 0;

	uvRect.width = _texture->getSize().x / (float)_imageCount.x;
	uvRect.height = _texture->getSize().y / (float)_imageCount.y;
}


Animation::~Animation()
{
}

void Animation::Update(int _row, float _deltaTime)
{
	currentImage.y = _row;
	totalTime += _deltaTime;

	if (totalTime >= switchTime) {
		totalTime = 0.0f;

		currentImage.x++;

		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}

		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
	}
}
