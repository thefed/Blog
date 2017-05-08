# makefile for cpp files
# usage: $ make SRC=001.twoSum.cpp && ./d
CC = g++
CFLAGS = -Wall -g -std=c++11 

#EXT = ""		#.cpp
SRC = LinkedList.cpp	# source cpp file name

all: d			# executable name

d: $(SRC)$(EXT)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.o d *.out
	@rm -rf *.dSYM	 # remove debug files
