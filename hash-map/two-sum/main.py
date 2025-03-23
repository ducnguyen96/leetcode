from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        myMap = {}
        for idx in range(len(nums)):
            if  target - nums[idx] in myMap:
                return [myMap[target - nums[idx]], idx]
            else:
                myMap[nums[idx]] = idx
        return []
