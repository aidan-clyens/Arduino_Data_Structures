#include <iostream>
#include "vector.h"

using namespace std;

int main() {
  vector<int> vec;

  for (int i = 0; i < 50; ++i) {
    vec.push_back(i*2);
  }

  cout << vec << endl;
  cout << "front = " << vec.front() << endl;
  cout << "back = " << vec.back() << endl;
  cout << "size = " << vec.size() << endl;
  cout << "capacity = " << vec.capacity() << endl << endl;

  for (int i = 0; i < 40; ++i) {
    vec.pop_back();
  }

  cout << vec << endl;
  cout << "front = " << vec.front() << endl;
  cout << "back = " << vec.back() << endl;
  cout << "size = " << vec.size() << endl;
  cout << "capacity = " << vec.capacity() << endl;


  return 0;
}
