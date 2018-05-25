/****************************************************
 *  Max Heap Example
 *
 *  NOTE: DOES NOT WORK
 *
 *  Aidan Clyens
 *  May 24, 2018
 */
#include <MaxHeap.h>

MaxHeap<int> heap;
 
void setup() {
  Serial.begin(9600);
  //  Print heap capacity
  Serial.print("Created max heap with capacity = ");
  Serial.println(heap.capacity());

  //  Push new elements to the heap
  heap.push(10);
  heap.push(5);
  heap.push(15);
  heap.push(8);
  heap.push(7);
  heap.push(3);

  //  Print the number of elements in the heap
  Serial.print("size = ");
  Serial.println(heap.size());
  //  Print the element at the top of the heap
  Serial.print("top = ");
  Serial.println(heap.top());

  //  Pop elements from the heap
  heap.pop();
  heap.pop();
  heap.pop();
  Serial.println("Popped 3 elements from the heap.");

  //  Print the number of elements in the heap
  Serial.print("size = ");
  Serial.println(heap.size());
  //  Print the element at the top of the heap
  Serial.print("top = ");
  Serial.println(heap.top());
}

void loop() {
  //  Empty
}
