all: bin/play_gol create_gifs

clean:
	rm -f bin/*
	rm -f obj/*
	rm *.gif

obj/gol.o: include/gol.hpp src/gol.cpp
	g++ -c -o obj/gol.o -Iinclude -Wall -Wextra src/gol.cpp

bin/play_gol: obj/gol.o src/play_gol.cpp
	g++ -o bin/play_gol -Iinclude -Wall -Wextra src/play_gol.cpp obj/gol.o

create_gifs: bin/play_gol
	examples/glider.sh
	examples/glider_gun.sh
	examples/pentadecathalon.sh
	examples/toad.sh
	examples/pulsar.sh

