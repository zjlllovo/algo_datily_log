#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int partition(vector<int> &vec, int low, int high) {
  int pivot = vec[high];
  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (vec[j] < pivot) {
      ++i;
      std::swap(vec[i], vec[j]);
    }
  }
  std::swap(vec[i + 1], vec[high]);
  return i + 1;
}

void quickSort(vector<int> &vec, int low, int high) {
  if (low < high) {
    int pi = partition(vec, low, high);
    quickSort(vec, low, pi - 1);
    quickSort(vec, pi + 1, high);
  }
}

template <typename T> void print(vector<T> vec) {
  for (auto it : vec) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
  quickSort(vec, 0, vec.size() - 1);
  print(vec);
  return 0;
}
