from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    total: int = 0

    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return self.total

        self.total += 1
        self.countNodes(root.left)
        self.countNodes(root.right)

        return self.total
