#include "snake.h"
#include "food.h"
#include "grid.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

	sf::RenderWindow window(sf::VideoMode({600, 600}), "snake game");
	// window.setFramerateLimit(60);

	Grid grid;
	grid.load();

	Food food;
	food.load();

	Snake snake;
	snake.load();

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

		snake.update(deltaTime, grid, window);

		if (snake.headPosition.x == food.foodPosition.x && 
		    snake.headPosition.y == food.foodPosition.y) {
			snake.increaseSnake();

			if (snake.snakeSpeed < 3.0f) {
				snake.snakeSpeed += 0.1f;
			}

			food.spawn();

			for (int i = 0; i < snake.body.size(); i++) {
				if (food.foodPosition.x == snake.body[i].getPosition().x/20 &&
				    food.foodPosition.y == snake.body[i].getPosition().y/20) {
					food.spawn();
					break;
				}
			}

			food.shape.setPosition(sf::Vector2f(food.foodPosition.x * 20.0f, food.foodPosition.y * 20.0f));
			
		}	

		window.clear(sf::Color::Black);

		grid.draw(window);
		
		snake.drawMovement(window);

		food.draw(window);

		window.display();
	}
} 

/* NOTE TO MYSELF:
 * introduce obstacles in the grid 
 * and give the player the option to calculate the shortest path between snake head and food 
 */
