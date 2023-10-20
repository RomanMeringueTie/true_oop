all: app

app: main.cpp life_game.cpp 
	g++ -I ~/oop/cw -Wall -o app main.cpp life_game.cpp -lsfml-graphics -lsfml-window -lsfml-system

life_game.o: life_game.cpp
	g++ -c -I ~/oop/cw -Wall -o app life_game.o -lsfml-graphics -lsfml-window -lsfml-system


.PHONY: run

run: app
	./app

.PHONY: clean

clean: app
	rm app