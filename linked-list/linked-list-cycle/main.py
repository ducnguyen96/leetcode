import sys
from typing import List, Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False

        left = head
        right = head.next
        while left and right:
            left = left.next
            right = right.next
            if left == right:
                return True
            if right:
                right = right.next

        return False


def main() -> int:
    solution = Solution()
    return 0


if __name__ == "__main__":
    sys.exit(main())
