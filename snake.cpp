#include "snake.h"
#include <iostream>

void Snake::load() {

	body.push_back(sf::RectangleShape {sf::Vector2f({20.0f, 20.0f})});
	body[0].setPosition({0.0f, 0.0f});
	body[0].setFillColor(sf::Color::Green);
}

void Snake::update(float deltaTime) {
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		body[0].move(sf::Vector2f({0.0f, -10.0f}) * speed * deltaTime);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		body[0].move(sf::Vector2f({-10.0f, 0.0f}) * speed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		body[0].move(sf::Vector2f({0.0f, 10.0f}) * speed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		body[0].move(sf::Vector2f({10.0f, 0.0f}) * speed * deltaTime);
	}

}

void Snake::setSpeed(float snakeSpeed) {
	speed = snakeSpeed;
}

void Snake::drawMovement(sf::RenderWindow& window) {

	window.draw(body[0]);

	for (int i = body.size() - 1; i > 0; i--) {
		body[i].setPosition(body[i-1].getPosition());
		window.draw(body[i]);
	}
}

void Snake::drawStatic(sf::RenderWindow& window) {
	
	for (int i = 0; i < body.size(); i++) {
		window.draw(body[i]);
	}
}

void Snake::increaseSnake() {
	body.push_back(sf::RectangleShape {sf::Vector2f({10.0f, 10.0f})});
	int index = body.size() - 1;

	body[index].setFillColor(sf::Color::Yellow);
}
