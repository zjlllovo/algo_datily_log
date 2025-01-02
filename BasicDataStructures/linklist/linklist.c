#include "linklist.h"

#include <stdio.h>
#include <stdlib.h>

void print(List *list) {
  Node *cur = list->head;
  while (cur) {
    printf("%d\n", cur->data);
    cur = cur->next;
  }
}

List *initList() {
  List *list = (List *)malloc(sizeof(List));
  if (!list) {
    perror("list_create_error");
  }
  list->head = NULL;
  list->size = 0;
  return list;
}

void destory(List *list) {
  Node *cur = list->head;
  while (cur) {
    Node *next = cur->next;
    free(cur);
    cur = next;
  }
  free(list);
}

bool isEmpty(List *list) { return list->head == NULL; }

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void push_head(List *list, int val) {
  Node *new_node = create_node(val);
  new_node->next = list->head;
  list->head = new_node;
  list->size++;
}

void push_back(List *list, int val) {
  Node *new_node = create_node(val);
  if (isEmpty(list)) {
    list->head = new_node;
  } else {
    Node *cur = list->head;
    while (cur->next) {

      cur = cur->next;
    }
    cur->next = new_node;
  }
  list->size++;
}

// 在对应的索引插入节点
void insert(List *list, int idx, int val) {
  if (idx < 0 || idx > list->size) {
    perror("Illegal Augament");
    exit(1);
  }
  if (idx == 0) {
    push_head(list, val);
  }
  // 找到idx前一个节点 idx-1
  Node *cur = list->head;
  for (int i = 0; i < idx - 1; i++) {
    cur = cur->next;
  }
  Node *new_node = create_node(val);
  new_node->next = cur->next;
  cur->next = new_node;
  list->size++;
}

// 删除第一个值与val相等的节点
void del_by_value(List *list, int val) {
  if (isEmpty(list)) {
    perror("list is empty!");
    exit(1);
  }
  if (list->head->data == val) {
    Node *cur = list->head;
    list->head = list->head->next;
    free(cur);
    list->size--;
  }
  Node *cur = list->head;
  while (cur->next != NULL && cur->next->data != val) {
    cur = cur->next;
  }
  if (cur->next != NULL) {
    Node *toDelete = cur->next;
    cur->next = toDelete->next;
    free(toDelete);
    list->size--;
  } else {
    perror("not found in the list");
  }
}

Node *search_by_val(List *list, int val) {
  Node *cur = list->head;
  while (cur) {
    if (cur->data == val) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

Node *find_by_index(List *list, int idx) {
  if (idx < 0 || idx >= list->size) {
    perror("Illegal Augament");
    exit(1);
  }
  Node *cur = list->head;
  for (int i = 0; i < idx; i++) {
    cur = cur->next;
  }
  return cur;
}
