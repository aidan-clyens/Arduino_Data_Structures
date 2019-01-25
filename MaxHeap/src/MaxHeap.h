/***********************************************************/
/*    Max Heap
/*
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    Aidan Clyens
/*    May 31, 2018
/***********************************************************/
#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#ifdef ARDUINO_H
#include "Arduino.h"
#else
#include <iostream>
#endif

#include "../include/Vector.h"

template <typename Type>
class MaxHeap {
  public:
    MaxHeap( int = 16 );
    ~MaxHeap();

    //  Size
    int size() const;
    bool empty() const;

    //  Element Access
    Type top() const;

    //  Modifers
    void push( const Type & );
    void pop();

    //  Misc.
    void print();
    bool is_max_heap( int );

  private:
    void swap( Type &, Type &);
    void percolate_up( int );
    void percolate_down( int );

    vector<Type> heap;
};

/***************************************
*           Constructors
****************************************/
/*
 * Default Heap Constructor
 */
template <typename Type>
MaxHeap<Type>::MaxHeap(int n) {
  vector<Type> heap(n);
}

/*
 * Heap Destructor
 */
template <typename Type>
MaxHeap<Type>::~MaxHeap() {
  //  Empty
}

/***************************************
*        Public Size Functions
****************************************/
/* size
 * Returns the size of the heap.
 */
template <typename Type>
int MaxHeap<Type>::size() const {
  return heap.size();
}

/* empty
 * Returns whether the heap is empty or not.
 */
template <typename Type>
bool MaxHeap<Type>::empty() const {
  return (size() == 0);
}

/***************************************
*    Public Element Access Functions
****************************************/
/* top
 * Return the element at the top of the heap.
 */
template <typename Type>
Type MaxHeap<Type>::top() const {
  return heap.front();
}

/***************************************
*       Public Modifier Functions
****************************************/
/* push
 * Push an element to the bottom of the heap and percolate it up.
 */
template <typename Type>
void MaxHeap<Type>::push(const Type &obj) {
  heap.push_back(obj);
  percolate_up(size() - 1);
}

/* pop
 * Pop an element from the top of the heap and percolate new top down
 * if necessary.
 */
template <typename Type>
void MaxHeap<Type>::pop() {
  heap.front() = heap.back();
  heap.pop_back();
  percolate_down(0);
}

/***************************************
*            Misc. Functions
****************************************/
/* print_heap
 * Print the heap contents.
 */
template <typename Type>
void MaxHeap<Type>::print() {
  heap.print();
}

/* is_max_heap
 * Returns whether or not the container is a correct max heap.
 */
template <typename Type>
bool MaxHeap<Type>::is_max_heap(int n) {
  int left = 2*n + 1;
  int right = 2*n + 2;
  bool is_heap = true;
  //  If the current node has a right child, check that it is less than the current node
  if (right < size()) {
    if (heap[right] <= heap[n] && is_max_heap(right)) is_heap = true;
    else return false;
  }
  //  If the current node has a left child, check that is is less than the current node
  if (left < size()) {
    if (heap[left] <= heap[n] && is_max_heap(left)) is_heap = true;
    else return false;
  }

  return is_heap;
}

/***************************************
*         Private Functions
****************************************/
/* swap
 * Swap two elements.
 */
template <typename Type>
void MaxHeap<Type>::swap(Type &a, Type &b) {
  Type temp = a;
  a = b;
  b = temp;
}

/* percolate_up
 * When pushing to the heap, move the new element up if the
 * parent is less than the new element.
 */
template <typename Type>
void MaxHeap<Type>::percolate_up(int n) {
  int parent = (n - 1) / 2;
  //  If the parent of the current node is less than the current node,
  //  swap and check the parent recursively
  if (heap[parent] < heap[n]) {
    swap(heap[parent], heap[n]);
    percolate_up(parent);
  }
}

/* percolate_down
 * When popping the top element of the heap, check the children of
 * the new top to make sure they are less than the new top.
 */
template <typename Type>
void MaxHeap<Type>::percolate_down(int n) {
  int left = 2*n + 1;
  int right = 2*n + 2;
  int max;
  //  The current node has no children, so return
  if (left > size() - 1) return;
  //  If the current node has two children, compare both
  if (right < size()) {
    max = (heap[left] > heap[right]) ? left : right;
  } else {
    max = left;
  }
  //  If the maximum of the node's children is greater than the current node,
  //  swap and check the subtree recursively
  if (heap[n] < heap[max]) {
    swap(heap[n], heap[max]);
    percolate_down(max);
  }
}

#endif
