exec = interstellar
projdir = ../

objects = ../../../objects
title = $(objects)/title.cpp
spaceobject = $(objects)/spaceobject.cpp
background = $(objects)/background.cpp

all:
	g++ -c test-view.cpp $(title) $(spaceobject) $(background)
	g++ test-view.o title.o spaceobject.o background.o -o interstellar -lsfml-graphics -lsfml-window -lsfml-system

testmake:
	@echo $(pwd)


clean:
	rm *.o
	rm interstellar