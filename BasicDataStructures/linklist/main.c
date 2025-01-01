#include "linklist.h"

int main() {
  List *list = create();
  push_back(list, 1);
  push_back(list, 2);
  push_back(list, 3);
  print(list);
  return 0;
}
