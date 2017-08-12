#include "Player.h"


Player::Player(Scene* _scene)
{
	input = _scene->input;
	plane = new JSprite(_scene->GetScene(), "../Assets/Art/Plane/Yellow/plane.png", false, true);

	planeAnimation = new Animation(&plane->GetTexture(), sf::Vector2u(4, 1), 0.2f);

	gravity = 1.0f;
	groundHeight = 432;

	isJumping = false;

	jumpSpeed = 10.0f;

	velocity = sf::Vector2f(0, 0);

	crashed = false;
}


Player::~Player()
{
}

void Player::Start()
{
}

void Player::Update(float _deltaTime)
{
	planeAnimation->Update(0, _deltaTime);
	plane->GetSprite().setTextureRect(planeAnimation->uvRect);

	if (plane->GetSprite().getPosition().y > 0 && (plane->GetSprite().getPosition().y + plane->GetTexture().getSize().y / 2) <= groundHeight && !crashed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			isJumping = true;
			velocity.y = -jumpSpeed;
		}
		if (plane->GetSprite().getPosition().y + plane->GetSprite().getScale().y < groundHeight || velocity.y < 0)
		{
			velocity.y += gravity;
		}

		plane->GetSprite().move(velocity.x, velocity.y);
	}
	else {
		crashed = true;
	}
}

JSprite & Player::GetJSprite()
{
	return *plane;
}

bool Player::GetCrashedState()
{
	return crashed;
}
