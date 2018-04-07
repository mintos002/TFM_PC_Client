#Compilation of the program
CC=g++
CFLAGS=-c -Wall -std=c++11
CFF=-Wall -std=c++11
DPC=main.o communication.o print_out.o data_handler.o

all: MainTest

MainTest: $(DPC)
	$(CC) $(CFF) $(DPC) -o MainTest

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

communication.o: communication.cpp print_out.o data_handler.o
	$(CC) $(CFLAGS) communication.cpp

print_out.o: print_out.cpp
	$(CC) $(CFLAGS) print_out.cpp

data_handler.o: data_handler.cpp print_out.o
	$(CC) $(CFLAGS) data_handler.cpp

clean:
	rm -rf *o MainTest
