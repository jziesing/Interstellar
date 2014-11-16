all: main.cpp spaceobject.cpp UFO.cpp
	g++ -c main.cpp spaceobject.cpp UFO.cpp
	g++ main.o spaceobject.o UFO.o -o test-app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm test-app
	rm *.o