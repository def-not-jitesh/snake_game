#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>

class Grid {
	public:
		void load();
		void update();
		void draw(sf::RenderWindow& window);

	private:

		sf::RectangleShape gridBlocks[30][30];
		
};

#endif
