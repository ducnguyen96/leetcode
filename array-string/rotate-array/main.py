from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        r = k % n
        if n == 1 or k == 0 or r == 0:
            return
        idx = 0
        prevIdx = idx
        prev = nums[prevIdx]
        for i in range(n):
            idx += r
            if idx >= n:
                idx -= n

            tmp = nums[idx]
            nums[idx] = prev
            prev = tmp

            if idx == prevIdx:
                idx += 1
                prevIdx = idx
                prev = nums[prevIdx]
