#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food {
	public:
		void load();
		void update();
		void draw(sf::RenderWindow& window);

	private:
		sf::RectangleShape shape {sf::Vector2f({10.0f, 10.0f})};

};

#endif
