from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        major = 0
        dup = 0
        for num in nums:
            if dup == 0:
                major = num
            dup += 1 if major == num else -1
        return major
