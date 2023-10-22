all: app

life_game.o: life_game.cpp
	g++ -c -I . -Wall -o life_game.o life_game.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

app: main.cpp life_game.o
	g++ -I . -Wall -o app main.cpp life_game.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

.PHONY: run

run: app
	./app

.PHONY: clean

clean: app
	rm app
	rm *.o