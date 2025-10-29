#include "snake.h"
#include "food.h"

#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode({800, 600}), "snake game");
	window.setFramerateLimit(60);

	Food food;
	food.load();

	Snake snake;
	snake.load();
	snake.setSpeed(100.0f);

	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();
	snake.increaseSnake();

	sf::Clock clock;

	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) 
				window.close();
		}

		sf::Time elapsedTime = clock.restart();
		float deltaTime = elapsedTime.asSeconds();

		snake.update(deltaTime);

		window.clear(sf::Color::Black);
		
		snake.draw(window);
		food.draw(window);

		window.display();
	}
} 
