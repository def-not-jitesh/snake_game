#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
	
	public:

		sf::Vector2f headPosition {};
		std::vector<sf::RectangleShape> body;

		void load();
		void update(float deltaTime);

		void drawMovement(sf::RenderWindow& window);
		void drawStatic(sf::RenderWindow& window);

		void setSpeed(float snakeSpeed);

		void increaseSnake();

	private:
		
		float speed {};
};

#endif
