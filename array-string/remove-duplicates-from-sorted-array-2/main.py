from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        dup = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[k]:
                k += 1
                nums[k] = nums[i]
                dup = 1
            elif dup < 2:
                k += 1
                nums[k] = nums[i]
                dup += 1
        return k + 1
