CC = g++
exe_file = run_students
$(exe_file): student_db.o driver.o
	$(CC) student_db.o driver.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
student_db.o: student_db.cpp
	$(CC) -c student_db.cpp

clean:
	rm -f *.out *.o $(exe_file)