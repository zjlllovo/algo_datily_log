#include <stdio.h>

int partition(int *vec, int low, int high) {
  int pivot = vec[high];
  int i = low - 1;
  int tmp = 0;
  for (int j = low; j < high; ++j) {
    if (vec[j] < pivot) {
      ++i;
      tmp = vec[i];
      vec[i] = vec[j];
      vec[j] = tmp;
    }
  }

  tmp = vec[i + 1];
  vec[i + 1] = vec[high];
  vec[high] = tmp;
  return i + 1;
}

void quickSort(int *vec, int low, int high) {
  if (low < high) {
    int pi = partition(vec, low, high);
    quickSort(vec, low, pi - 1);
    quickSort(vec, pi + 1, high);
  }
}

int main() {
  int vec[] = {64, 34, 25, 12, 22, 11, 90};
  quickSort(vec, 0, sizeof(vec) / sizeof(int) - 1);
  for (int i = 0; i < sizeof(vec) / sizeof(int) - 1; i++) {
    printf("%d ", vec[i]);
  }
  return 0;
}
