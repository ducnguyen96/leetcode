from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        target = targetSum - root.val

        if target == 0 and root.left is None and root.right is None:
            return True

        return self.hasPathSum(root.left, target) or self.hasPathSum(root.right, target)
