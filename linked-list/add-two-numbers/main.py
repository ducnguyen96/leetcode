
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        head = ListNode()
        current = head
        remain = 0

        while l1 or l2:
            sum = l1.val + l2.val + remain
            current.val = sum % 10
            remain = sum // 10

            if not l1.next and not l2.next:
                break

            if l1.next:
                l1 = l1.next
            else:
                l1.val = 0

            if l2.next:
                l2 = l2.next
            else:
                l2.val = 0

            current.next = ListNode()
            current = current.next
        if remain > 0:
            current.next = ListNode(remain)

        return head

