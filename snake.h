#ifndef SNAKE_H
#define SNAKE_H

#include "grid.h"
#include <SFML/Graphics.hpp>
#include <vector>

enum class Direction {
	Up, 
	Down, 
	Right,
	Left
};

class Snake {
	
	public:

		Position headPosition;
		std::vector<sf::RectangleShape> body;

		float snakeSpeed = {1.0f};

		void load();
		void update(float deltaTime, const Grid& grid, sf::RenderWindow& window);

		void drawMovement(sf::RenderWindow& window);

		void increaseSnake();

		float moveDelay = 0.20f;
		float delayTimer {};

		bool hasLost();

		Direction currentDirection = Direction::Right;

};

#endif
