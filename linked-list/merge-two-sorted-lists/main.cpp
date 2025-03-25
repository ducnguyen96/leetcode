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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1 && !list2)
      return nullptr;
    auto head = new ListNode();
    auto current = head;

    while (list1 || list2) {
      if (!list1) {
        current->val = list2->val;
        current->next = list2->next;
        break;
      }
      if (!list2) {
        current->val = list1->val;
        current->next = list1->next;
        break;
      }

      if (list1->val < list2->val) {
        current->val = list1->val;
        list1 = list1->next;
      } else {
        current->val = list2->val;
        list2 = list2->next;
      }
      current->next = new ListNode();
      current = current->next;
    }

    return head;
  }
};

int main(int argc, char *argv[]) {
  auto l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  auto l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  auto sol = new Solution();
  auto l = sol->mergeTwoLists(l1, l2);
  while (l) {
    cout << l->val << " ";
    l = l->next;
  }
  return 0;
}
