from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    minimum: int = 100000
    prev = None

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return self.minimum

        self.getMinimumDifference(root.left)

        if self.prev is not None:
            self.minimum = min(self.minimum, root.val - self.prev)
        self.prev = root.val

        self.getMinimumDifference(root.right)

        return self.minimum
