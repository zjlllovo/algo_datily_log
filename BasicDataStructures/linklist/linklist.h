#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} List;

List *initList();
void destory(List *list);
bool isEmpty(List *list);
Node *create_node(int data);
void push_head(List *list, int val);
void push_back(List *list, int val);
void insert(List *list, int idx, int val);
void del_by_value(List *list, int val);
Node *find_by_index(List *list, int idx);
Node *search_by_val(List *list, int val);
void print(List *list);
