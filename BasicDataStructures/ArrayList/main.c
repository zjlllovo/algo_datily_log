#include "arraylist.h"

int main() {
  ArrayList *al = create();
  for (int i = 0; i < 50; i++) {
    push_back(al, i);
    printf("%d\n", al->elements[i]);
  }
  destroy(al);
  return 0;
}
