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

List *create() {
  List *list = (List *)malloc(sizeof(List));
  if (!list) {
    perror("list_create_error");
  }
  list->head = NULL;
  list->tail = NULL;
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

void push_head(List *list, int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = val;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
  list->size++;
}

void push_back(List *list, int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = val;
  new_node->next = NULL;
  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
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
  if (idx == list->size) {
    push_back(list, val);
  }
  // 找到idx前一个节点 idx-1
  Node *cur = list->head;
  for (int i = 0; i < idx - 1; i++) {
    cur = cur->next;
  }
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = val;
  new_node->next = cur->next;
  cur->next = new_node;
  list->size++;
}

// 删除第一个值与val相等的节点
void del_node(List *list, int val) {
  Node *prev = NULL;
  Node *cur = list->head;
  while (cur) {
    if (cur->data == val) {
      // 删除cur
      if (prev == NULL) {
        list->head = cur->next;
        if (list->tail == cur) {
          list->tail = NULL;
        }
      } else {
        prev->next = cur->next;
        if (list->tail == cur) {
          list->tail = prev;
        }
      }
      list->size--;
      free(cur);
      return;
    }
    prev = cur;
    cur = cur->next;
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
