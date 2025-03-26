from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ans: List[float] = []

        level: List[Optional[TreeNode]] = [root]

        while len(level) > 0:
            tmp = []
            sum = 0.0
            for node in level:
                sum += node.val
                if node.left:
                    tmp.append(node.left)
                if node.right:
                    tmp.append(node.right)
            ans.append(sum / len(level))
            level = tmp

        return ans
