#include "food.h"

void Food::load() {
	shape.setPosition({100.0f, 100.0f});
}

void Food::draw(sf::RenderWindow& window) {
	window.draw(shape);
}
