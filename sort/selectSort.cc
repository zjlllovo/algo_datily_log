#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void selectSort(vector<int> &arr) {
  for (size_t i = 0; i < arr.size() - 1;
       ++i) { // i记录已经排好序的元素个数 记录最最小元素的目标index
    size_t minIndex = i;
    for (size_t j = i + 1; j < arr.size(); ++j) { // 筛选出一趟的最小元素
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(arr[i], arr[minIndex]);
  }
}

template <typename T> void print(vector<T> arr) {
  for (auto it : arr) {
    cout << it << " ";
  }
  cout << endl;
}
int main() {
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  selectSort(arr);
  print(arr);
  return 0;
}
