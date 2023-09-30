all: app

app: 6.cpp 
	g++ -Wall -o app 6.cpp -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: run

run: app
	./app

.PHONY: clean

clean: app
	rm app