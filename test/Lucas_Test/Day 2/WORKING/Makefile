errors: main-test.cpp UFO2.cpp
	g++ -c main-test.cpp UFO2.cpp
	g++ main-test.o UFO2.o -o test-app -lsfml-graphics -lsfml-window -lsfml-system

current: current-main.cpp UFO.cpp
	g++ -c current-main.cpp UFO.cpp
	g++ current-main.o UFO.o -o test-app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm test-app
	rm *.o