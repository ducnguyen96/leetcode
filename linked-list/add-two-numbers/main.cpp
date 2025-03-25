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
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    ListNode *current = head;

    int remain = 0;
    while (l1 != nullptr || l2 != nullptr) {
      int sum = l1->val + l2->val + remain;
      current->val = sum % 10;
      remain = sum / 10;

      if (!l1->next && !l2->next) {
        break;
      }

      if (!l1->next) {
        l1->val = 0;
      } else {
        l1 = l1->next;
      }
      if (!l2->next) {
        l2->val = 0;
      } else {
        l2 = l2->next;
      }
      current->next = new ListNode();
      current = current->next;
    }

    if (remain)
      current->next = new ListNode(remain);

    return head;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();
  ListNode *l1 =
      new ListNode(2, new ListNode(4, new ListNode(3, new ListNode(9))));
  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  auto head = sol->addTwoNumbers(l1, l2);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }

  return 0;
}
