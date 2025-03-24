from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        rs = []
        n = len(nums)
        start = 0
        end = 1
        while end <= n:
            if end == n or nums[end] > nums[end - 1] + 1:
                num_start = str(nums[start])
                if start == end - 1:
                    rs.append(num_start)
                else:
                    rs.append(num_start + "->" + str(nums[end - 1]))
                start = end
            end += 1
        return rs
