/****************************************************
 *  QueueArray Example
 *
 *  Aidan Clyens
 *  May 17, 2018
 */
#include <QueueArray.h>

//  Create a QueueArray of type 'int'
QueueArray<int> queue;

void setup() {
  Serial.begin(9600);
  
  //  Push new elements to the queue
  queue.push(10);
  queue.push(20);
  queue.push(5);
  queue.push(12);
  queue.push(15);
  queue.push(5);

  //  Pop elements from the queue
  queue.pop();
  queue.pop();

  //  Print the number of elements in the queue
  Serial.print("size = ");
  Serial.println(queue.size());
  //  Print the element at the front of the queue
  Serial.print("front = ");
  Serial.println(queue.front());
  //  Print the element at the back of the queue
  Serial.print("back = ");
  Serial.println(queue.back());
  //  Print the linked queue to the serial monitor
  queue.print();

  //  Clear all elements in the original queue
  queue.clear();
  queue.print();

}

void loop() {
  //  Empty
}
