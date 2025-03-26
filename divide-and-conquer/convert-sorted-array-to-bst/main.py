from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def build(self, nums: List[int], start: int, end: int) -> Optional[TreeNode]:
        if start > end:
            return None

        mid = round(float(end - start) / 2)
        mid += start
        val = nums[mid]
        node = TreeNode(val)
        node.left = self.build(nums, start, mid - 1)
        node.right = self.build(nums, mid + 1, end)

        return node

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.build(nums, 0, len(nums) - 1)
