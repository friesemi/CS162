CC = g++
exe = aVb
$(exe): driver.o insects.o bees.o ants.o harvester.o thrower.o fire.o longThrower.o shortThrower.o wall.o ninja.o bodyguard.o game.o
	$(CC) driver.cpp insects.cpp bees.cpp ants.cpp harvester.cpp thrower.cpp fire.cpp longThrower.cpp shortThrower.cpp wall.cpp ninja.cpp bodyguard.cpp game.cpp -o $(exe)
driver.o: driver.cpp
	$(CC) -c driver.cpp
insects.o: insects.cpp
	$(CC) -c insects.cpp
bees.o: bees.cpp
	$(CC) -c bees.cpp
ants.o: ants.cpp
	$(CC) -c ants.cpp
harvester.o: harvester.cpp
	$(CC) -c harvester.cpp
thrower.o: thrower.cpp
	$(CC) -c thrower.cpp
fire.o: fire.cpp
	$(CC) -c fire.cpp
longThrower.o: longThrower.cpp
	$(CC) -c longThrower.cpp
shortThrower.o: shortThrower.cpp
	$(CC) -c shortThrower.cpp
wall.o: wall.cpp
	$(CC) -c wall.cpp
ninja.o: ninja.cpp
	$(CC) -c ninja.cpp
bodyguard.o: bodyguard.cpp
	$(CC) -c bodyguard.cpp
game.o: game.cpp
	$(CC) -c game.cpp

clean:
	rm -f *.out *.o $(exe)


