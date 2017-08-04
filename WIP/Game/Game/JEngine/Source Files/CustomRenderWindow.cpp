#include "../Header Files/CustomRenderWindow.h"
#include "../Header Files/InputManager.h"

CustomRenderWindow::CustomRenderWindow()
{
	window.create(sf::VideoMode(768, 432), "Game", sf::Style::Close);
	sf::Image icon;

	icon.loadFromFile(pathToIconImage);

	window.setIcon(32, 32, icon.getPixelsPtr());

	windowSize = window.getSize();
	isDone = false;
	window.setFramerateLimit(60);
}

CustomRenderWindow::~CustomRenderWindow()
{
}

void CustomRenderWindow::BeginDraw() {
	window.clear(sf::Color::Black);
}
void CustomRenderWindow::EndDraw() {
	window.display();
}

void CustomRenderWindow::Draw(sf::Drawable& _drawable) {
	window.draw(_drawable);
}

sf::Vector2u CustomRenderWindow::GetWindowSize() {
	return windowSize;
}

sf::RenderWindow* CustomRenderWindow::GetWindow()
{
	return &window;
}
