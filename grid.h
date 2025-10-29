#ifndef GRID_H
#define GRID_H

#include "grid.h"
#include <SFML/Graphics.hpp>

struct Position {
	int x {};
	int y {};
};

class Grid {
	public:
		void load();
		void update();
		void draw(sf::RenderWindow& window);


		sf::RectangleShape gridBlocks[30][30];
		
};

#endif
