#include "snake.h"
#include "food.h"
#include "grid.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

	sf::RenderWindow window(sf::VideoMode({600, 600}), "snake game");
	window.setFramerateLimit(60);

	Grid grid;
	grid.load();

	Food food;
	food.load();

	Snake snake;
	snake.load();
	snake.setSpeed(100.0f);

	sf::Clock clock;

	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) 
				window.close();
		}

		snake.headPosition.x = snake.body[0].getPosition().x/20; 
		snake.headPosition.y = snake.body[0].getPosition().y/20; 

		sf::Time elapsedTime = clock.restart();
		float deltaTime = elapsedTime.asSeconds();

		snake.update(deltaTime, grid);

		if (food.shape.getPosition() == snake.body[0].getPosition()) {
			snake.increaseSnake();

			float xCoordinate = food.randomCoordinate(0);
			float yCoordinate = food.randomCoordinate(1);

			food.shape.setPosition(sf::Vector2f({xCoordinate, yCoordinate}));
		}	

		window.clear(sf::Color::Black);

		grid.draw(window);
		
		snake.drawMovement(window);
		food.draw(window);

		window.display();
	}
} 
