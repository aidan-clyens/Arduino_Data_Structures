/***********************************************************/
/*    Max Heap
/*
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    NOTE: DOES NOT WORK
/*
/*    Aidan Clyens
/*    May 25, 2018
/***********************************************************/

#ifndef MAX_HEAP_ARDUINO_H
#define MAX_HEAP_ARDUINO_H

#include "Arduino.h"

template <typename Type>
class MaxHeap {
  public:
    MaxHeap( int = 16 );
    ~MaxHeap();

    //  Accessor Functions
    int size() const;
    bool empty() const;
    Type top() const;
    int capacity() const;

    //  Mutator Functions
    void push( Type const & );
    void pop();

  private:
    void heapify( Type * );
    void swap( Type &, Type &);

    int heap_size;
    int heap_capacity;
    Type *heap;
};

//  The default MaxHeap constructor
template <typename Type>
MaxHeap<Type>::MaxHeap( int n ):
heap_size( 0 ),
heap_capacity( n ),
heap( new Type[n] )
{
  //  Empty constructor
}

//  The MaxHeap destructor
template <typename Type>
MaxHeap<Type>::~MaxHeap() {
  delete[] heap;
}

/**** Public Accessor Functions ****/

//  Return the element at the top of the heap
template <typename Type>
Type MaxHeap<Type>::top() const {
  return heap[0];
}

//  Return whether the heap is empty or not
template <typename Type>
bool MaxHeap<Type>::empty() const {
  return (heap_size == 0);
}

//  Return the size of the heap
template <typename Type>
int MaxHeap<Type>::size() const {
  return heap_size;
}

//  Return the capacity of the heap
template <typename Type>
int MaxHeap<Type>::capacity() const {
  return heap_capacity;
}

/**** Public Mutator Functions ****/

//  Push an element to the bottom of the heap and percolate it up appropriately
template <typename Type>
void MaxHeap<Type>::push( Type const &obj ) {
  if (heap_size == heap_capacity) return;

  heap[heap_size] = obj;
  ++heap_size;

  heapify(heap - 1);
}

//  Pop an element from the top of the heap and percolate all children up appropriately
template <typename Type>
void MaxHeap<Type>::pop() {
  heap[0] = 0;
  heapify(heap - 1);

  --heap_size;
}

/**** Private Mutator Functions ****/
//  Turn the array into a max heap
template <typename Type>
void MaxHeap<Type>::heapify(Type *array) {
  for (int i = heap_size/2; i >= 1; --i) {
    int index = i;
    int left = 2*i;
    int right = 2*i + 1;
    //  Percolate down
    while (right <= heap_size) {
      if (array[left] > array[right] && array[left] > array[index]) {
        swap(array[index], array[left]);
      } else if (array[right] > array[index]) {
        swap(array[index], array[right]);
      } else {
        break;
      }
    }

    if (left == heap_size && array[left] > array[index]) {
      swap(array[index], array[left]);
    }
  }
}

//  Swap two objects
template <typename Type>
void MaxHeap<Type>::swap(Type &a, Type &b) {
  Type temp = a;
  a = b;
  b = temp;
}

#endif
