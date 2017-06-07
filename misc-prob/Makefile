# makefile for cpp files
# usage: $ make SRC=001.twoSum.cpp && ./d
CC = g++
CFLAGS = -Wall -g -std=c++11 

SRC = LinkedList.cpp	# source cpp file name

all: d			# executable name

d: $(SRC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.o d; rm -rf *.dSYM # remove debug files
