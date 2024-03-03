all: bin/start_gol

clean:
	rm -f bin/*
	rm -f obj/*

obj/gol.o: include/gol.hpp src/gol.cpp
	g++ -c -o obj/gol.o -Iinclude -Wall -Wextra src/gol.cpp

bin/start_gol: obj/gol.o src/play_gol.cpp
	g++ -o bin/play_gol -Iinclude -Wall -Wextra src/play_gol.cpp obj/gol.o

