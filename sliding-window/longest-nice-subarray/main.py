from typing import List


class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        n = len(nums)

        left = 0
        right = 0

        maxLength = 0
        mask = 0
        while right < n:
            while (mask & nums[right]) != 0:
                mask ^= nums[left]
                left += 1
            mask |= nums[right]
            maxLength = max(maxLength, right - left + 1)
            right += 1

        return maxLength
