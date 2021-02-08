exe = zombie
cc = g++
files = driver.o bee.o ant.o header.o
execute: $(files)
	$(cc) $(files) -o $(exe)
%.o: $(@:%.o=%.cpp)
	$(cc) -c $(@:%.o=%.cpp)
clean: 
	rm -f *.o *.out zombie
