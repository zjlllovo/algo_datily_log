// 时间复杂度：最坏o(n^2) 平均o(n^2) 最好o(n) 稳定
// 空间复杂度：o(1)
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void bubbleSort(vector<int> &arr) {
  for (
      size_t i = 0; i < arr.size() - 1;
      ++i) { // i-1
             // 是必要的,表示只需要运行到数组长度-1，因为最后一次内循环已经确定好了
    for (size_t j = 0; j < arr.size() - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
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
  bubbleSort(arr);
  print(arr);
  return 0;
}

// 冒泡排序的思想是:
// 两重循环，外循环收缩窗口，内循环比较相邻两项的大小，
// 一次大循环确定好一个元素的正确排序，同时窗口收缩，
// 外循环结束，完成排序。
