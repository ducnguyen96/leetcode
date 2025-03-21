#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head) {
      return false;
    }

    auto left = head;
    auto right = head->next;
    while (left && right) {
      left = left->next;
      right = right->next;
      if (left == right) {
        return true;
      }
      if (right) {
        right = right->next;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  auto head = new ListNode(3);
  auto node1 = new ListNode(2);
  auto node2 = new ListNode(0);
  auto node3 = new ListNode(4);

  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node1;

  auto rs = solution->hasCycle(head);
  cout << rs << endl;

  return 0;
}
