#include "snake.h"
#include <iostream>

void Snake::load() {
	
	headPosition.x = 15;
	headPosition.y = 15;

	body.push_back(sf::RectangleShape {sf::Vector2f({20.0f, 20.0f})});
	body[0].setPosition(sf::Vector2f(headPosition.x * 20.0f, headPosition.y * 20.0f));
	body[0].setFillColor(sf::Color::Green);

}

void Snake::update(float deltaTime, const Grid& grid) {
	
	delayTimer += deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		headPosition.y--;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		headPosition.x--;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		headPosition.y++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		headPosition.x++;
	}

	if (delayTimer > moveDelay) {
		body[0].setPosition(grid.gridBlocks[headPosition.x][headPosition.y].getPosition());
		delayTimer = 0.0f;
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
	body.push_back(sf::RectangleShape {sf::Vector2f({20.0f, 20.0f})});
	int index = body.size() - 1;

	body[index].setFillColor(sf::Color::Yellow);
}
