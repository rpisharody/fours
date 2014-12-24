all: objs

objs: rand.o game.o
	g++ -Wall -O2 main.c -o fours rand.o game.o
rand.o: rand.h rand.c
	g++ -Wall -O2 -c -o rand.o rand.c
game.o: game.h game.c 
	g++ -Wall -O2 -c -o game.o game.c

clean:
	-rm *.o
