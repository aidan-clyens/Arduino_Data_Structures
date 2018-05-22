/****************************************************
 *  Linked List Example
 *
 *  Aidan Clyens
 *  May 9, 2018
 */
#include <LinkedList.h>

//  Create a linked list of type 'int'
LinkedList<int> list;

void setup() {
  //  Push new elements to the back of the linked list
  list.push_back(10);
  list.push_back(20);
  list.push_back(5);
  //  Push new elements to the front of the linked list
  list.push_front(12);
  list.push_front(15);
  list.push_front(5);

  //  Pop an element from the back of the linked list
  list.pop_back();

  //  Pop an element from the front of the linked list
  list.pop_front();

  Serial.begin(9600);
  //  Print the number of elements in the linked list
  Serial.print("size = ");
  Serial.println(list.size());
  //  Print the element at the front of the linked list
  Serial.print("front = ");
  Serial.println(list.front());
  //  Print the element at the back of the linked list
  Serial.print("back = ");
  Serial.println(list.back());
  //  Print the linked list to the serial monitor
  list.print_list();

  //  Create a copy of the original linked list
  LinkedList<int> list_copy(list);
  list_copy.print_list();

  //  Clear all elements in the original linked list
  list.clear();
  list.print_list();

}

void loop() {
  //  Empty
}
