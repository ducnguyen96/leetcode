#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  ListNode *_mid(ListNode *node) {
    ListNode *slow = node, *fast = node;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    auto mid = slow->next;
    slow->next = nullptr; // cắt đuôi

    return mid;
  }

  ListNode *merge(ListNode *left, ListNode *right) {
    auto *tail = new ListNode();
    auto dummy = tail;

    while (left && right) {
      if (left->val < right->val) {
        tail->next = left;
        tail = left;
        left = left->next;
      } else {
        tail->next = right;
        tail = right;
        right = right->next;
      }
    }

    tail->next = left ? left : right;

    return dummy->next;
  }

public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) { // phải có ít nhất 2 nodes để lấy mid
      return head;
    }

    auto mid = _mid(head);
    cout << mid->val << endl;

    auto left = sortList(head);
    auto right = sortList(mid);

    return merge(left, right);
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  auto head =
      new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
  auto sorted = sol->sortList(head);

  while (sorted) {
    cout << sorted->val << " ";
    sorted = sorted->next;
  }

  return 0;
}
