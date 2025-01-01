#include "arraylist.h"
#include <stdlib.h>

ArrayList *create() {
  ArrayList *handle = (ArrayList *)malloc(sizeof(ArrayList));
  int *e = (int *)malloc(DEFAULT_CAPACITY * sizeof(int));
  handle->elements = e;
  handle->size = 0;
  handle->capcitity = DEFAULT_CAPACITY;
  return handle;
}

void destroy(ArrayList *al) {
  free(al->elements);
  free(al);
}

void grow(ArrayList *al) {
  int newcapacity = al->capcitity < PREALLOC_MAX ? al->capcitity << 1
                                                 : al->capcitity + PREALLOC_MAX;

  int *p = realloc(al->elements, newcapacity * sizeof(int));
  if (!p) {
    perror("realloc error");
    exit(1);
  }

  al->elements = p;
  al->capcitity = newcapacity;
}

void push_back(ArrayList *al, int val) {
  if (al->size == al->capcitity) {
    grow(al);
  }
  al->elements[al->size] = val;
  al->size++;
}
