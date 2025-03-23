from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        myMap = {}
        for idx in range(len(nums)):
            num = nums[idx]
            if num in myMap:
                if idx - myMap[num][len(myMap[num]) - 1] <= k:
                    return True
                else:
                    myMap[num].append(idx)
            else:
                myMap[num] = [idx]
        return False
