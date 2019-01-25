/***********************************************************/
/*    QueueList
/*
/*    This is an implementation used a custom Linked List
/*    class.
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    Aidan Clyens
/*    May 17, 2018
/***********************************************************/
#ifndef QUEUE_LIST_ARDUINO_H
#define QUEUE_LIST_ARDUINO_H

#ifdef ARDUINO_H
#include "Arduino.h"
#endif

#include "../include/LinkedList.h"

template <typename Type>
class QueueList {
  public:
    QueueList();
    QueueList( QueueList const & );
    ~QueueList();

    //  Accessor Functions
    int size() const;
    bool empty() const;
    Type front() const;
    Type back() const;

    //  Mutator Functions
    void push( Type const & );
    void pop();
    void clear();

    void print();

  private:
    LinkedList<Type> queue;
};

/*************************************/
/**********     Queue       **********/
/*************************************/

//  Default QueueList Constructor
template <typename Type>
QueueList<Type>::QueueList() {
  //  Empty Constructor
}

//  QueueList Copy Constructor
template <typename Type>
QueueList<Type>::QueueList(QueueList<Type> const &copy) {
  queue = copy.queue;
}

//  QueueList Destructor
template <typename Type>
QueueList<Type>::~QueueList() {
  queue.clear();
}

/****** QueueList Accessor Functions ******/

//  Return the size of the queue
template <typename Type>
int QueueList<Type>::size() const {
  return queue.size();
}

//  Returns a boolean value stating if the queue is empty
template <typename Type>
bool QueueList<Type>::empty() const {
  return queue.empty();
}

//  Return the element at the front of the queue
template <typename Type>
Type QueueList<Type>::front() const {
  return queue.front();
}

//  Return the element at the back of the queue
template <typename Type>
Type QueueList<Type>::back() const {
  return queue.back();
}

/****** QueueList Mutator Functions  ******/

//  Push a new element to the back of the queue
template <typename Type>
void QueueList<Type>::push(Type const &obj) {
  queue.push_back(obj);
}

//  Pop the element at the front of the list
template <typename Type>
void QueueList<Type>::pop() {
  queue.pop_front();
}

//  Clears all the elements in the queue
template <typename Type>
void QueueList<Type>::clear() {
  queue.clear();
}

//  Print the queue on the Arduino serial monitor
template <typename Type>
void QueueList<Type>::print() {
  queue.print();
}

#endif
