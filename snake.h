#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
	
	public:

		void load();
		void update(float deltaTime);
		void draw(sf::RenderWindow& window);

		void setSpeed(float snakeSpeed);

		void increaseSnake();

	private:
		
		float speed {};
		std::vector<sf::RectangleShape> body;
};

#endif
