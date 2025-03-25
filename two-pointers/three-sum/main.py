from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()

        ans: List[List[int]] = []
        prev = -nums[0] - 1

        for i in range(n-2):
            target = -nums[i]
            if target == prev:
                continue
            prev = target

            start, end = i+1, n-1
            while start < end:
                sum = nums[start] + nums[end]
                if sum == target:
                    ans.append([-target, nums[start], nums[end]])
                    currentStart = nums[start]
                    currentEnd = nums[end]
                    while nums[start] == currentStart and start < end:
                        start += 1
                    while nums[end] == currentEnd and start < end:
                        end -= 1
                elif sum > target:
                    end -= 1
                else:
                    start += 1
        return ans
