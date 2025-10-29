#include "grid.h"
#include <array>

void Grid::load() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			gridBlocks[i][j] = sf::RectangleShape {sf::Vector2f({20.0f, 20.0f})};
			gridBlocks[i][j].setPosition(sf::Vector2f({i*20.0f, j*20.0f}));
			gridBlocks[i][j].setFillColor(sf::Color::Black);
		}
	}
}

void Grid::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			window.draw(gridBlocks[i][j]);
		}
	}

	for (int i = 1; i < 30; i++) {
		std::array line = {
			sf::Vertex{sf::Vector2f({0.0f, i * 20.0f})}, 
			sf::Vertex{sf::Vector2f({600.0f, i * 20.0f})}
		};

		window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
	}

	for (int i = 1; i < 30; i++) {
		std::array line = {
			sf::Vertex{sf::Vector2f({i * 20.0f, 0.0f})}, 
			sf::Vertex{sf::Vector2f({i * 20.0f, 600.f})}
		};

		window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
	}

} 
