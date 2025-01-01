#include <stdio.h>

#define DEFAULT_CAPACITY 8
#define PREALLOC_MAX 1024

typedef struct {
  int size;
  int capcitity;
  int *elements;
} ArrayList;

ArrayList *create();
void destroy(ArrayList *al);
void grow(ArrayList *al);
void push_back(ArrayList *al, int value);
