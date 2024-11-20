#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T> void print(vector<T> &vec) {
  for (auto it : vec) {
    cout << it << " ";
  }
  cout << endl;
}

void heapify(vector<int> &arr, int n, int i) { // 构建大根堆的逻辑
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n &&
      arr[left] > arr[largest]) { // left< n,防止 子节点超过数组大小的情况
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(vector<int> &arr) {
  for (int i = arr.size() / 2 - 1; i >= 0;
       --i) { // 第一次构建大根堆,移除最大元素
    heapify(arr, arr.size(), i);
  }
  for (int i = arr.size() - 1; i > 0;
       --i) { // 重复构建大根堆，每一次重建找一个出最大值放到数组末尾
    std::swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  vector<int> vec = {64, 34, 90, 12, 22, 11, 25};
  heapSort(vec);
  print(vec);
  return 0;
}
