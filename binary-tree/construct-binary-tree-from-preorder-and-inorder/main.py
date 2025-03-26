from typing import Dict, List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    preorderIdx: int

    myMap: Dict[int, int]

    def build(self, preorder: List[int], start: int, end: int) -> Optional[TreeNode]:
        if start > end:
            return None

        val = preorder[self.preorderIdx]
        root = TreeNode(val)
        self.preorderIdx += 1

        mid = self.myMap[val]
        root.left = self.build(preorder, start, mid - 1)
        root.right = self.build(preorder, mid + 1, end)

        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.preorderIdx = 0
        self.myMap = {}

        for idx in range(len(inorder)):
            self.myMap[inorder[idx]] = idx

        return self.build(preorder, 0, len(preorder) - 1)
