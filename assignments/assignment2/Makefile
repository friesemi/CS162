CC = g++
exe_file = pizza_shop
$(exe_file): driver.o menu.o pizza.o restaurant.o player.o
	$(CC) driver.cpp menu.cpp pizza.cpp restaurant.cpp player.cpp -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
menu.o: menu.cpp
	$(CC) -c menu.cpp
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
restaurant.o: restaurant.cpp
	$(CC) -c restaurant.cpp
player.o: player.cpp
	$(CC) -c player.cpp

clean:
	rm -f *.out *.o $(exe_file)