#include "food.h"

#include <cstdlib>

void Food::load() {

	foodPosition.x = 10;
	foodPosition.y = 10;

	shape.setPosition({foodPosition.x * 20.0f, foodPosition.y * 20.0f});
	shape.setFillColor(sf::Color::Red);
}

void Food::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

void Food::randomCoordinate(int axis) {

	if (axis == 0) {
		foodPosition.x = rand() % 30;
	}
		
	else {
		foodPosition.y = rand() % 30;
	}
}

