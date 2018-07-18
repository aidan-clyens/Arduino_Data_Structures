# Hash Table Arduino
This is a Hash Table class that uses quadratic probing and a simple hash function (outlined below), which was written using C++ to be used with Arduino sketches


## Getting Started
1. Move the HashTable folder to your Arduino libraries folder, contained in your sketchbook folder.
2. Use `#include <HashTable.h>` at the top of your sketch or click Sketch -> Include Library -> HashTable.

## Functionality
Constructors:
- Default constructor

Size Accessor Functions:
- int size
- int capacity
- bool empty

Element Access Functions:
- Type at

Modifier Functions:
- void insert
- bool erase
- void clear

Misc. Functions:
- double load_factor
- void print

## Hash Function
`int HashTable<Type>::hash(Type const &obj) const {
    int n = static_cast<int>(obj);
    int hash = n % array_capacity;

    return (hash >= 0) ? hash : hash + array_capacity;
}`

## Author
Copyright (c) 2018 Aidan Clyens
