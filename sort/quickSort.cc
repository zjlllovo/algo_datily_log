#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;

int main() {
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  quickSort(arr);
  print(arr);
  return 0;
}
