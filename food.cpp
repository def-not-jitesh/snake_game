#include "food.h"

#include <cstdlib>

void Food::load() {
	shape.setPosition({100.0f, 100.0f});
	shape.setFillColor(sf::Color::Red);
}

void Food::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

float Food::randomCoordinate(int axis) {

	if (axis == 0) 
		return rand() % 790;
	else 
		return rand() % 590;
}

