/***********************************************************/
/*    Queue
/*
/*    This is an implementation using arrays. Currently, there
/*    is no dynamic array resizing.
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    Aidan Clyens
/*    May 23, 2018
/***********************************************************/
#ifndef QUEUE_ARDUINO_H
#define QUEUE_ARDUINO_H

#include "Arduino.h"

template <typename Type>
class Queue {
  public:
    Queue( int = 16 );
    ~Queue();

    //  Accessor Functions
    int size() const;
    bool empty() const;
    Type front() const;
    Type back() const;

    //  Mutator Functions
    void push( Type const & );
    void pop();
    void clear();

    void print_queue();

  private:
    Type* queue;
    int queue_size;
    int queue_capacity;
    int front_index;
    int back_index;
};

/*************************************/
/**********     Queue       **********/
/*************************************/

//  Default Queue Constructor
template <typename Type>
Queue<Type>::Queue(int n):
queue_capacity( n ),
queue_size( 0 ),
queue( new Type[n] ),
front_index( 0 ),
back_index( -1 )
{
  //  Empty Constructor
}

//  Queue Destructor
template <typename Type>
Queue<Type>::~Queue() {
  delete[] queue;
}

/****** Queue Accessor Functions ******/

//  Return the size of the queue
template <typename Type>
int Queue<Type>::size() const {
  return queue_size;
}

//  Returns a boolean value stating if the queue is empty
template <typename Type>
bool Queue<Type>::empty() const {
  return (queue_size == 0);
}

//  Return the element at the front of the queue
template <typename Type>
Type Queue<Type>::front() const {
  return queue[front_index];
}

//  Return the element at the back of the queue
template <typename Type>
Type Queue<Type>::back() const {
  return queue[back_index];
}

/****** Queue Mutator Functions  ******/

//  Push a new element to the back of the queue
template <typename Type>
void Queue<Type>::push(Type const &obj) {
  if (queue_size == queue_capacity) return;
  //  Move back index forwards, accounting for array wraparound
  back_index = ++back_index % queue_capacity;
  queue[back_index] = obj;
  ++queue_size;
}

//  Pop the element at the front of the list
template <typename Type>
void Queue<Type>::pop() {
  if (empty()) return;
  //  Move front index forwards, accounting for array wraparound
  front_index = ++front_index % queue_capacity;
  --queue_size;
}

//  Clears all the elements in the queue
template <typename Type>
void Queue<Type>::clear() {
  delete[] queue;
  queue = new Type[queue_capacity];

  queue_size = 0;
  front_index = 0;
  back_index = -1;
}

//  Print the queue on the Arduino serial monitor
template <typename Type>
void Queue<Type>::print_queue() {
  if (empty()) return;

  int i = front_index;

  while (i != back_index) {
    Serial.print(queue[i]);
    Serial.print(" ");
    i = ++i % queue_capacity;
  }
  Serial.println(queue[back_index]);
}

#endif
