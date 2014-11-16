all: main.cpp title.cpp
	icpc -c main.cpp title.cpp -lcilkrts
	icpc main.o title.o -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm main
	rm *.o
