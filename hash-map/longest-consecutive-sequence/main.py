from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)

        mySet = set(nums)
        longest = 1
        for num in mySet:
            if num - 1 not in mySet:
                current = num
                count = 1
                while current + 1 in mySet:
                    current += 1
                    count += 1
                longest = max(longest, count)
        return longest
