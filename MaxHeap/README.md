# Max Heap Arduino
This is a Max Heap class which was written using C++ to be used with Arduino sketches. The MaxHeap class is implemented using my custom vector class.

## Getting Started
1. Move the MaxHeap folder to your Arduino libraries folder, contained in your sketchbook folder.
2. Use `#include <MaxHeap.h>` at the top of your sketch or click Sketch -> Include Library -> MaxHeap.

## Functionality
Constructors:
- Default constructor

Size Accessor Functions:
- int size
- bool empty

Element Access Functions:
- Type top

Modifier Functions:
- void push
- void pop

Misc:
- void print_heap
- bool is_max_heap

## Author
Copyright (c) 2018 Aidan Clyens
