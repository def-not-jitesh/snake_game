CC := g++
OBJ := game.o snake.o food.o grid.o
FLAGS := -lsfml-graphics -lsfml-system -lsfml-window
BINARY := game 

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(FLAGS) $^ -o $(BINARY)

%.o: %.cpp
	$(CC) $^ -c -o $@

clean:
	rm $(BINARY) $(OBJ)
