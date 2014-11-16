all: main.cpp title.cpp
	g++ -c main.cpp title.cpp -lcilkrts
	g++ main.o title.o -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm main
	rm *.o
