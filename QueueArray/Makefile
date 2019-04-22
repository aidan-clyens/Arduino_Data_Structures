CC=g++
CFLAGS=-std=c++11 -g
SRC=./src
LIB=./lib
EX=./examples
NAME=QueueArray

all: example $(NAME).o

example:
	if [ -d $(EX)/example ]; then rm -f $(EX)/example; fi
	$(CC) $(CFLAGS) -o $(EX)/example $(EX)/example.cpp
$(NAME).o:
	if [ -d $(LIB)/$(NAME).o ]; then rm -f $(LIB)/$(NAME).o; fi
	$(CC) $(CFLAGS) -o $(LIB)/$(NAME).o $(SRC)/$(NAME).h

clean:
	if [ -d $(EX)/example ]; then rm -f $(EX)/example; fi
