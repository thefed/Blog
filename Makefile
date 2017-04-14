CC = g++
CFLAGS = -Wall -g -std=c++11 

#EXT = .cpp
SRC = LinkedList.cpp
#SRC = combination
#SRC = search

all: d

d: $(SRC)$(EXT)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.o d *.out
