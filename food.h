#ifndef FOOD_H
#define FOOD_H

#include "grid.h"
#include <SFML/Graphics.hpp>

class Food {
	public:
		void load();
		void update();
		void draw(sf::RenderWindow& window);

		const sf::RectangleShape getShape();

		float randomCoordinate(int axis);

		sf::RectangleShape shape {sf::Vector2f({20.0f, 20.0f})};

		Position foodPosition;

};

#endif
