all: 1 2

run: 3

1:
	g++ -c Main.cpp Game.cpp State.cpp MainMenu.cpp InfoScreen.cpp ActualGame.cpp -I/mnt/d/LABOLATORIA/ProgramyC++/SFML-2.5.1/include -std=c++17
2:
	g++ Main.o Game.o State.o MainMenu.o InfoScreen.o ActualGame.o -o sfml-app -L/mnt/d/LABOLATORIA/ProgramyC++/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
3:
	export LD_LIBRARY_PATH=/mnt/d/LABOLATORIA/ProgramyC++/SFML-2.5.1/lib && ./sfml-app

clean:
	rm -rf *.o