#include <stdio.h>

struct ListNode {
  ListNode *next;
  int val;
};

ListNode *reverseList(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  reverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return head->next;
}

int main() { return 0; }
