all: view2.cpp title.cpp
	g++ -c view2.cpp title.cpp
	g++ view2.o title.o -o view-app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm view-app
	rm *.o