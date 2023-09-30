all: app

app: 4.cpp 
	g++ -Wall -o app 4.cpp -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: run

run: app
	./app

.PHONY: clean

clean: app
	rm app