all: app

app: 3.cpp 
	g++ -Wall -o app 3.cpp -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: run

run: app
	./app

.PHONY: clean

clean: app
	rm app