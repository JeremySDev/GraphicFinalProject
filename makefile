CC=clang++
LDLIBS=-lGL -lGLU -lglut
all:  run
LegoBuilder: LegoBuilder.o LegoBrick.o run
	$(CC) $(LDLIBS) LegoBuilder.cpp LegoBrick.cpp -o LegoBuilder.out

LegoBrick.o: LegoBrick.cpp
	$(CC) -c LegoBrick.cpp $(LDLIBS) 

LegoBuilder.o: LegoBuilder.cpp
	$(CC) -c LegoBuilder.cpp $(LDLIBS) 

run: LegoBuilder
	./LegoBuilder.out &

clean:
	rm -f *.o LegoBuilder.out
.PHONY: all clean
