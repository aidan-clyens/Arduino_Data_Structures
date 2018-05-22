# Linked List Based Queue Arduino
This is a Queue class which is built using a custom Linked List, which was written using C++ to be used with Arduino sketches.

## Getting Started
1. Move the ListBasedQueue folder to your Arduino libraries folder, contained in your sketchbook folder.
2. Use `#include <Queue.h>` at the top of your sketch or click Sketch -> Include Library -> QueueArduino.

## Functionality
Constructors:
- Default constructor
- Copy constructor

Accessor Functions:
- int size
- bool empty
- Type front
- Type back

Mutator Functions:
- void push
- void pop
- void clear

Misc:
- void print_queue

## Author
Copyright (c) 2018 Aidan Clyens
