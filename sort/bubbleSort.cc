#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T> void print(vector<T> vec) {
  for (auto &it : vec) {
    cout << it << ' ';
  }
  cout << endl;
}

template <typename T> void bubbleSort(vector<T> &arr) {}

int main() {
  vector<int> vec = {5, 3, 8, 4, 2};
  print(vec);
  return 0;
}
