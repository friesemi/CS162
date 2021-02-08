CC = g++
exe_file = lab1_functions
$(exe_file): lab1_functions.o lab1.o
	$(CC) lab1_functions.o lab1.o -o $(exe_file)
lab1_functions.o: lab1_functions.cpp
	$(CC) -c lab1_functions.cpp
lab1.o: lab1.cpp
	$(CC) -c lab1.cpp

clean:
	rm -f *.out *.o $(exe_file)