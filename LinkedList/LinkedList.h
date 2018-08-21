/***********************************************************/
/*    Doubly Linked List
/*
/*    Uses sentinel nodes at the head and tail of the linked
/*    list.
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    Aidan Clyens
/*    May 9, 2018
/***********************************************************/
#ifndef LINKED_LIST_ARDUINO_H
#define  LINKED_LIST_ARDUINO_H

#include "Arduino.h"

template <typename Type>
class LinkedList {
  public:
    class Node {
      public:
        Node( Type const & = Type(), Node * = nullptr, Node * = nullptr );

        //  Element Access
        Type value() const;
        Node* next() const;
        Node* previous() const;

        Type node_value;
        Node *next_node;
        Node *previous_node;
    };

    LinkedList();
    LinkedList( LinkedList const & );
    ~LinkedList();

    //  Size
    int size() const;
    bool empty() const;

    //  Element Access
    Type front() const;
    Type back() const;
    Node* begin() const;
    Node* end() const;
    Node* rbegin() const;
    Node* rend() const;
    Node* find() const;

    //  Modifiers
    void push_front( Type const & );
    void push_back( Type const & );
    void pop_front();
    void pop_back();
    void clear();

    //  Misc.
    void print();

  private:
    int list_size;
    Node *list_head;
    Node *list_tail;
};

/***********************************************/
/***************   LinkedList    ***************/
/***********************************************/
/***************************************
*           Constructors
****************************************/
/*
 * Linked List Default Constructor
 */
template <typename Type>
LinkedList<Type>::LinkedList():
list_head( new Node() ),
list_tail( new Node() ),
list_size( 0 )
{
  list_head->next_node = list_tail;
  list_tail->previous_node = list_head;
}

/*
 * Linked List Copy Constructor
 */
template <typename Type>
LinkedList<Type>::LinkedList(LinkedList<Type> const &list):
list_head( new Node() ),
list_tail( new Node() ),
list_size( 0 )
{
  list_head->next_node = list_tail;
  list_tail->previous_node = list_head;

  for (Node *ptr = list.begin(); ptr != list.end(); ptr = ptr->next()) {
    push_back(ptr->value());
  }
}

/*
 * Linked List Destructor
 */
template <typename Type>
LinkedList<Type>::~LinkedList() {
  clear();

  delete list_head;
  delete list_tail;
}

/***************************************
          Public Size Functions
****************************************/
/*
 * size
 * Returns the linked list size
 */
template <typename Type>
int LinkedList<Type>::size() const {
  return list_size;
}

/*
 * empty
 * Returns a boolean value stating if the linked list is empty
 */
template <typename Type>
bool LinkedList<Type>::empty() const {
  return (list_size == 0);
}

/***************************************
*     Public Element Access Functions
****************************************/
/*
 * front
 * Returns the element at the front of the linked list
 */
template <typename Type>
Type LinkedList<Type>::front() const {
  return (!empty()) ? begin()->value() : Type();
}

/*
 * back
 * Returns the element at the end of the linked list
 */
template <typename Type>
Type LinkedList<Type>::back() const {
  return (!empty()) ? rbegin()->value() : Type();
}

/*
 * begin
 * Returns the address of the first node in the linked list
 */
template <typename Type>
typename LinkedList<Type>::Node *LinkedList<Type>::begin() const {
  return list_head->next();
}

/*
 * end
 * Returns the address of the tail sentinel node of the linked list_tail
 */
template <typename Type>
typename LinkedList<Type>::Node *LinkedList<Type>::end() const {
  return list_tail;
}

/*
 * rbegin
 * Returns the address of the last node in the linked list
 */
template <typename Type>
typename LinkedList<Type>::Node *LinkedList<Type>::rbegin() const {
  return list_tail->previous();
}

/*
 * rend
 * Returns the address of the head sentinel node of the linked list_tail
 */
template <typename Type>
typename LinkedList<Type>::Node *LinkedList<Type>::rend() const {
  return list_head;
}

/***************************************
*       Public Modifier Functions
****************************************/
/*
 * push_front
 * Pushs a new object to the front of the linked list
 */
template <typename Type>
void LinkedList<Type>::push_front(Type const &obj) {
  //  Store current first node in the list and create a new empty node
  Node *temp = begin();
  Node *node = new Node(obj, temp, list_head);
  //  Reassign pointers at the head of the list
  list_head->next_node = node;
  temp->previous_node = node;
  ++list_size;
}

/*
 * push_back
 * Pushs a new object to the back of the linked list
 */
template <typename Type>
void LinkedList<Type>::push_back(Type const &obj) {
  //  Store the current last node in the list and create a new empty node
  Node *temp = rbegin();
  Node *node = new Node(obj, list_tail, temp);
  //  Reassign pointers at the tail of the list
  list_tail->previous_node = node;
  temp->next_node = node;
  ++list_size;
}

/*
 * pop_front
 * Pops the object from the front of the linked list
 */
template <typename Type>
void LinkedList<Type>::pop_front() {
  if (empty()) return;

  Node *temp = begin();
  temp->next()->previous_node = list_head;
  list_head->next_node = temp->next();
  delete temp;
  --list_size;
}

/*
 * pop_back
 * Pops the object from the back of the linked list
 */
template <typename Type>
void LinkedList<Type>::pop_back() {
  if (empty()) return;

  Node *temp = rbegin();
  temp->previous()->next_node = list_tail;
  list_tail->previous_node = temp->previous();
  delete temp;
  --list_size;
}

/*
 * clear
 * Deletes all of the elements in the linked list
 */
template <typename Type>
void LinkedList<Type>::clear() {
  while (!empty()) pop_front();
}

/***************************************
*         Public Misc. Functions
****************************************/
/*
 * print
 * Prints the list using Arduino serial communication
 */
template <typename Type>
void LinkedList<Type>::print() {
  Serial.print("head -> ");
  for (typename LinkedList<Type>::Node *ptr = begin(); ptr != end(); ptr = ptr->next()) {
    Serial.print(ptr->value());
    Serial.print(" -> ");
  }
  Serial.println("tail");
}

/***********************************************/
/***************       Node      ***************/
/***********************************************/
/***************************************
*           Constructors
****************************************/
/*
 * Default Node Constructor
 */
template <typename Type>
LinkedList<Type>::Node::Node(Type const &obj, typename LinkedList<Type>::Node *next, typename LinkedList<Type>::Node *previous):
node_value( obj ),
next_node( next ),
previous_node( previous )
{
  //  Empty
}

/***************************************
*         Element Access Functions
****************************************/
/*
 * value
 * Returns the node value
 */
template <typename Type>
Type LinkedList<Type>::Node::value() const {
  return node_value;
}

/*
 * next
 * Returns the address of the next node to the current node
 */
template <typename Type>
typename LinkedList<Type>::Node *LinkedList<Type>::Node::next() const {
  return next_node;
}

/*
 * previous
 * Returns the address of the previous node to the current node
 */
template <typename Type>
typename LinkedList<Type>::Node *LinkedList<Type>::Node::previous() const {
  return previous_node;
}

#endif
