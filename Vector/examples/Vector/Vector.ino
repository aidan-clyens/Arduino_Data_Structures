/****************************************************
 *  Vector Example
 *
 *  Aidan Clyens
 *  July 20, 2018
 */
 #include <vector.h>

//  Create a vector of type 'int' with an initial capacity of 10
 vector<int> vec(10);

 void setup() {
     Serial.begin(9600);

     // Push new elements to the back of the vector
     vec.push_back(10);
     vec.push_back(12);
     vec.push_back(3);
     vec.push_back(5);

     // Pop elements from the back of the vector
     vec.pop_back();
     vec.pop_back();

     // Get the size of the vector
     Serial.print("size = ");
     Serial.println(vec.size());

     // Get the current capacity of the vector
     Serial.print("capacity = ");
     Serial.println(vec.capacity());

     // Determine if the vector is empty or not
     Serial.print("empty: ");
     if (vec.empty()) Serial.println("True");
     else Serial.println("False");

     // Access an element at a specific index by reference
     Serial.print("The contents at index 1 is: ");
     Serial.println(vec.at(1));
     // Or using: vec[1]

     // Push elements to the back of the vector until over capacity to automatically
     // resize it to double capacity
     for (int i = 0; i < 15; ++i) {
         vec.push_back(2*i);
     }
     // Get the new vector size and capacity
     Serial.print("The new size is: ");
     Serial.println(vec.size());
     Serial.print("The new capacity is: ");
     Serial.println(vec.capacity());

     // Access the element at the back of the vector by reference
     Serial.print("The contents at the back of the vector is: ");
     Serial.println(vec.back());

     // Access the element at the front of thr vector by reference
     Serial.print("The contents at the front of the vector is: ");
     Serial.println(vec.front());
 }

 void loop() {
     // Empty
 }
