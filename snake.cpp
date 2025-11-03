#include "snake.h"
#include <iostream>

void Snake::load() {
	
	headPosition.x = 15;
	headPosition.y = 15;

	body.push_back(sf::RectangleShape {sf::Vector2f({20.0f, 20.0f})});
	body[0].setPosition(sf::Vector2f(headPosition.x * 20.0f, headPosition.y * 20.0f));
	body[0].setFillColor(sf::Color::Green);

}

void Snake::update(float deltaTime, const Grid& grid, sf::RenderWindow& window) {

	delayTimer += deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

		if (currentDirection != Direction::Down) {
			currentDirection = Direction::Up;
		}
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (currentDirection != Direction::Right) {
			currentDirection = Direction::Left;
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if (currentDirection != Direction::Up) {
			currentDirection = Direction::Down;
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (currentDirection != Direction::Left) {
			currentDirection = Direction::Right;
		}

	}

	 if (delayTimer > moveDelay/snakeSpeed) {

		for (int i = body.size() - 1; i > 0; i--) {
			body[i].setPosition(body[i-1].getPosition());
		}	

		switch (currentDirection) {
			case (Direction::Up):
				headPosition.y--;
				break;

			case (Direction::Right):
				headPosition.x++;
				break;

			case (Direction::Left):
				headPosition.x--;
				break;

			case (Direction::Down):
				headPosition.y++;
				break;
		
		}

		body[0].setPosition(grid.gridBlocks[headPosition.x][headPosition.y].getPosition());
		
		if (hasLost()) {
			window.close();
		}

		delayTimer = 0.0f;
	
 	}

}

void Snake::drawMovement(sf::RenderWindow& window) {
	
	for (int i = 0; i < body.size(); i++) {
		window.draw(body[i]);
	}

}

void Snake::increaseSnake() {
	body.push_back(sf::RectangleShape {sf::Vector2f({20.0f, 20.0f})});
	int index = body.size() - 1;

	body[index].setFillColor(sf::Color::Yellow);

	body[index].setPosition(body[index-1].getPosition());
}

bool Snake::hasLost() {
	if ((headPosition.x > 29 || headPosition.x < 0) ||
	    (headPosition.y > 29 || headPosition.y < 0)) {

	    	std::cout << "you have lost the game\n";
		return true;
	    }

	if (body.size() > 1) {
		for (int i = 1; i < body.size(); i++) {
			if (headPosition.x == body[i].getPosition().x/20 &&
			    headPosition.y == body[i].getPosition().y/20) {
				std::cout << "you have lost the game\n";
				return true;
			}
		}
	}
	
	return false;
}
