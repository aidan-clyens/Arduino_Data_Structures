# Vector Arduino
This is a Vector class which was written using C++ to be used with Arduino sketches. A vector is a container storing linear orderings, working the same way as an array. Though, the vector data structure is dynamically resizable, doubling capacity when vector reaches current capacity and halving capacity when vector reaches a quarter of the current capacity.

## Getting Started
1. Move the Vector folder to your Arduino libraries folder, contained in your sketchbook folder.
2. Use `#include <vector.h>` at the top of your sketch or click Sketch -> Include Library -> Vector.

## Functionality
Constructors:
- Default constructor

Size Accessor Functions:
- int size
- int capacity
- bool empty

Element Access Functions:
- Type at
- Type operator[]
- Type front
- Type back

Modifier Functions:
- void push_back
- void pop_back

Misc:
- void print

## Author
Copyright (c) 2018 Aidan Clyens
