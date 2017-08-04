#include "../Header Files/JButton.h"
#include "../Header Files/Game.h"

JButton::JButton(Scene * _scene, std::string _buttonImagePath) : scene(_scene)
{
	input = scene->input;
	buttonTexture.loadFromFile(_buttonImagePath);
	button.setTexture(buttonTexture);
}

JButton::~JButton()
{
}

bool JButton::OnClick(sf::Mouse::Button _mouseButton)
{
	if (hasPressedTexture) {
		bool click = input->OnMouse(this, _mouseButton);

		if (click) {
			button.setTexture(buttonPressedTexture);
		}
	}

	bool clickReleased = input->OnMouseRelease(this, _mouseButton);

	if (hasPressedTexture) {
		if (clickReleased) {
			button.setTexture(buttonTexture);
		}
	}

	return clickReleased;
}

void JButton::SetPressedImage(std::string _buttonImagePath)
{
	buttonPressedTexture.loadFromFile(_buttonImagePath);
	hasPressedTexture = true;
}

sf::Sprite& JButton::GetSprite()
{
	return button;
}
