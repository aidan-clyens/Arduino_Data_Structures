/****************************************************
 *  Search Tree Example
 *
 *  Aidan Clyens
 *  August 20, 2018
 */
#include <SearchTree.h>

//  Create a SearchTree of type 'int'
SearchTree<int> tree();

void setup() {
  Serial.begin(9600);

  //  Insert new elements to the search tree
  tree.insert(4);
  tree.insert(5);
  tree.insert(-2);
  tree.insert(7);
  tree.insert(1);
  tree.insert(-1);
  tree.insert(3);

  //  Erase elements from the search tree
  tree.erase(5);
  tree.erase(1);

  //  Get the size of the search tree
  Serial.print("size = ");
  Serial.println(tree.size());

  //  Get the height of the search tree
  Serial.print("height = ");
  Serial.println(tree.height());

  //  Determine if the search tree is empty or not
  Serial.print("empty: ");
  if (tree.empty()) Serial.println("True");
  else Serial.println("False");

  //  Find an element in the search tree, returns the address to the SearchNode
  Serial.print("find 3: ");
  Serial.println(tree.find(3));
  Serial.print("height of subtree at 3: ");
  Serial.println(tree.find(3)->height());

  //  Print the search tree to the serial monitor
  tree.print();

  //  Clear the search tree
  tree.clear();
}

void loop() {
  //  Empty
}
