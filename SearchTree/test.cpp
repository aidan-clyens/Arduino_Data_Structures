#include <iostream>
#include "SearchTree.h"

using namespace std;

int main() {
  cout << "****************** Create ******************" << endl;

  SearchTree<int> tree;

  cout << "height = " << tree.height() << endl;
  cout << "size = " << tree.size() << endl;
  cout << "empty = " << tree.empty() << endl;

  cout << "\n****************** Insert ******************" << endl;

  cout << "insert 2" << endl;
  tree.insert(2);
  cout << "insert 4" << endl;
  tree.insert(4);
  cout << "insert 6" << endl;
  tree.insert(6);
  cout << "insert 8" << endl;
  tree.insert(8);
  cout << "insert 5" << endl;
  tree.insert(5);
  cout << "insert 1" << endl;
  tree.insert(1);
  cout << "insert 3" << endl;
  tree.insert(3);
  cout << "insert -1" << endl;
  tree.insert(-1);
  cout << "insert -4" << endl;
  tree.insert(-4);
  cout << "insert -3" << endl;
  tree.insert(-3);

  cout << endl;

  cout << "height = " << tree.height() << endl;
  cout << "size = " << tree.size() << endl;
  cout << "empty = " << tree.empty() << endl;

  cout << endl;

  tree.print();

  cout << "\n****************** Erase ******************" << endl;

  cout << "erase 3" << endl;
  tree.erase(3);
  tree.print();
  cout << endl;
  cout << "erase 6" << endl;
  tree.erase(6);
  tree.print();
  cout << endl;
  cout << "erase 1" << endl;
  tree.erase(1);
  tree.print();
  cout << endl;

  cout << endl;

  cout << "height = " << tree.height() << endl;
  cout << "size = " << tree.size() << endl;
  cout << "empty = " << tree.empty() << endl;

  cout << endl;

  cout << "\n****************** Find ******************" << endl;

  cout << "Find -1: " << tree.find(-1) << endl;
  cout << "Find 8: " << tree.find(8) << endl << endl;

  cout << "-1 subtree height: " << tree.find(-1)->height() << endl;
  cout << "8 subtree height: " << tree.find(8)->height() << endl;

  return 0;
}
