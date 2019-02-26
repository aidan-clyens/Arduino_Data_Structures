CC=g++
CFLAGS=-std=c++11 -g
SRC=./src
LIB=./lib
EX=./examples
TESTS=$(SRC)/tests
NAME=HashTable

all: example $(NAME).o

example:
	if [ -d $(EX)/example ]; then rm -f $(EX)/example; fi
	$(CC) $(CFLAGS) -o $(EX)/example $(EX)/example.cpp
$(NAME).o:
	if [ -d $(LIB)/$(NAME).o ]; then rm -f $(LIB)/$(NAME).o; fi
	$(CC) $(CFLAGS) -o $(LIB)/$(NAME).o $(SRC)/$(NAME).h
test:
	rm -rf $(TESTS)/runTest
	cmake $(TESTS)/CMakeLists.txt
	$(MAKE) -C $(TESTS)
	$(TESTS)/runTest
