CC = g++
exe = tycoon
$(exe): property.o driver.o house.o apartment_complex.o business_complex.o player.o
	$(CC) property.cpp driver.cpp house.cpp apartment_complex.cpp business_complex.cpp player.cpp -o $(exe)
property.o: property.cpp
	$(CC) -c property.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
house.o: house.cpp
	$(CC) -c house.cpp
apartment_complex.o: apartment_complex.cpp
	$(CC) -c apartment_complex.cpp
business_complex.o: business_complex.cpp
	$(CC) -c business_complex.cpp
player.o: player.cpp
	$(CC) -c player.cpp

clean:
	rm -f *.out *.o $(exe)