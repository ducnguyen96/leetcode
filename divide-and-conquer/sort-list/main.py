from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def _merge(self, left: Optional[ListNode], right: Optional[ListNode]) -> ListNode:
        dummy = tail = ListNode()

        while left and right:
            if left.val < right.val:
                tail.next, tail, left = left, left, left.next
            else:
                tail.next, tail, right = right, right, right.next

        tail.next = left or right

        return dummy.next

    def _mid(self, node: ListNode) -> ListNode:
        slow, fast = node, node

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        mid = slow.next
        slow.next = None

        return mid

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        mid = self._mid(head)
        left = self.sortList(head)
        right = self.sortList(mid)
        return self._merge(left, right)
