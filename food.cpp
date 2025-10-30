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

int Food::randomCoordinate(int axis) {

	if (axis == 0) {
		return rand() % 29;
	}
		
	else {
		return rand() % 29;
	}
}

void Food::spawn() {
	foodPosition.x = randomCoordinate(0);
	foodPosition.y = randomCoordinate(1);
}



