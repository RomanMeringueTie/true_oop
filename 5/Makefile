all: app

app: 5.cpp 
	g++ -Wall -o app 5.cpp -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: run

run: app
	./app

.PHONY: clean

clean: app
	rm app