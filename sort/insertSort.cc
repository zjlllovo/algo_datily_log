#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void insertSort(vector<int> &arr) {
  for (size_t i = 1; i < arr.size(); ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

template <typename T> void print(vector<T> vec) {
  for (auto it : vec) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  insertSort(arr);
  print(arr);
  return 0;
}
