/***********************************************************/
/*    Queue
/*
/*    This is an implementation used a custom Linked List
/*    class.
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    Aidan Clyens
/*    May 17, 2018
/***********************************************************/
#ifndef QUEUE_ARDUINO_H
#define QUEUE_ARDUINO_H

#include "Arduino.h"
#include "LinkedList.h"

template <typename Type>
class Queue {
  public:
    Queue();
    Queue( Queue const & );
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
    LinkedList<Type> queue;
};

/*************************************/
/**********     Queue       **********/
/*************************************/

//  Default Queue Constructor
template <typename Type>
Queue<Type>::Queue() {
  //  Empty Constructor
}

//  Queue Copy Constructor
template <typename Type>
Queue<Type>::Queue(Queue<Type> const &copy) {
  queue = copy.queue;
}

//  Queue Destructor
template <typename Type>
Queue<Type>::~Queue() {
  queue.clear();
}

/****** Queue Accessor Functions ******/

//  Return the size of the queue
template <typename Type>
int Queue<Type>::size() const {
  return queue.size();
}

//  Returns a boolean value stating if the queue is empty
template <typename Type>
bool Queue<Type>::empty() const {
  return queue.empty();
}

//  Return the element at the front of the queue
template <typename Type>
Type Queue<Type>::front() const {
  return queue.front();
}

//  Return the element at the back of the queue
template <typename Type>
Type Queue<Type>::back() const {
  return queue.back();
}

/****** Queue Mutator Functions  ******/

//  Push a new element to the back of the queue
template <typename Type>
void Queue<Type>::push(Type const &obj) {
  queue.push_back(obj);
}

//  Pop the element at the front of the list
template <typename Type>
void Queue<Type>::pop() {
  queue.pop_front();
}

//  Clears all the elements in the queue
template <typename Type>
void Queue<Type>::clear() {
  queue.clear();
}

//  Print the queue on the Arduino serial monitor
template <typename Type>
void Queue<Type>::print_queue() {
  queue.print_list();
}

#endif
