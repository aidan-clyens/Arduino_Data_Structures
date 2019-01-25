/***********************************************************/
/*    Vector
/*
/*    A dynamically resizable vector data structure.
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    Aidan Clyens
/*    May 29, 2018
/***********************************************************/
#ifndef VECTOR_H
#define VECTOR_H

#ifdef ARDUINO_H
#include "Arduino.h"
#else
#include <iostream>
#endif

template <typename Type>
class vector {
  public:
    vector( int = 16 );
    ~vector();

    //  Size
    int size() const;
    int capacity() const;
    bool empty() const;

    //  Element Access
    Type &at( int ) const;
    Type &operator[]( int ) const;
    Type &front() const;
    Type &back() const;

    //  Modifiers
    void push_back( const Type & );
    void pop_back();

    //  Misc.
    void print();

  private:
    void double_capacity();
    void half_capacity();

    int vector_size;
    int vector_capacity;
    Type *array;
};

/***************************************
*           Constructors
****************************************/
/*
 * Default Vector Constructor
 */
template <typename Type>
vector<Type>::vector(int n):
vector_capacity( n ),
vector_size( 0 ),
array( new Type[n] )
{
  //  Empty
}

/*
 * Vector Destructor
 */
template <typename Type>
vector<Type>::~vector() {
  delete[] array;
}

/***************************************
*        Public Size Functions
****************************************/
/* size
 * Returns the size of the vector.
 */
template <typename Type>
int vector<Type>::size() const {
  return vector_size;
}

/* capacity
 * Returns the current capacity of the vector.
 */
template <typename Type>
int vector<Type>::capacity() const {
  return vector_capacity;
}

/* empty
 * Returns whether the vector is empty or not.
 */
template <typename Type>
bool vector<Type>::empty() const {
  return (vector_size == 0);
}

/***************************************
*    Public Element Access Functions
****************************************/
/* at
 * Returns the value at the specified index.
 */
template <typename Type>
Type &vector<Type>::at(int i) const {
    if (i >= vector_size) {
        //  TODO: Throw OutOfRange exception
    }
    return array[i];
}

/* operator[]
 * Returns the value at the specifed index, the same as the at() function.
 */
template <typename Type>
Type &vector<Type>::operator[](int i) const {
  if (i >= vector_size) {
      //    TDOD: Throw OutOfRange exception
  }
  return array[i];
}

/* front
 * Return the element at the back of the vector.
 */
template <typename Type>
Type &vector<Type>::front() const {
  return array[0];
}

/* back
 * Return the element at the back of the vector.
 */
template <typename Type>
Type &vector<Type>::back() const {
  return array[vector_size - 1];
}

/***************************************
*       Public Modifier Functions
****************************************/
/* push_back
 * Push a new element to the back of the vector.
 */
template <typename Type>
void vector<Type>::push_back(const Type &obj) {
  if (vector_size == vector_capacity) double_capacity(); //  Resize

  array[vector_size] = obj;
  ++vector_size;
}

/* pop_back
 * Remove the back element from the vector.
 */
template <typename Type>
void vector<Type>::pop_back() {
  if (empty()) return;
  if (vector_size <= vector_capacity / 4 && vector_capacity > 16) half_capacity();

  --vector_size;
}

/***************************************
*            Misc. Functions
****************************************/
/* print_vector
 * Print the vector contents.
 */
 template <typename Type>
 void vector<Type>::print() {
   for (int i = 0; i < size(); ++i) {
     #ifdef ARDUINO_H
     Serial.print(at(i));
     Serial.print(" ");
     #else
     std::cout << at(i) << " ";
     #endif
   }
   #ifdef ARDUINO_H
   Serial.println();
   #else
   std::cout << std::endl;
   #endif
 }

/***************************************
*         Private Functions
****************************************/
/* double_capacity
 * Double the capacity of the array used for the vector.
 */
template <typename Type>
void vector<Type>::double_capacity() {
  int new_capacity = 2 * vector_capacity;
  Type *temp = array;
  array = new Type[new_capacity];

  for (int i = 0; i < vector_size; ++i) {
    array[i] = temp[i];
  }

  vector_capacity = new_capacity;

  delete[] temp;
}

/* half_capacity
 * Half the capacity of the array used for the vector.
 */
template <typename Type>
void vector<Type>::half_capacity() {
  int new_capacity = vector_capacity / 2;
  Type *temp = array;
  array = new Type[new_capacity];

  for (int i = 0; i < vector_size; ++i) {
    array[i] = temp[i];
  }

  vector_capacity = new_capacity;

  delete[] temp;
}

#endif
