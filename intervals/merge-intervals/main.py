from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        if n == 1:
            return intervals

        ans: List[List[int]] = []

        intervals.sort(key=lambda interval: interval[0])
        start = intervals[0]
        end = 1

        while end <= n:
            if end == n or intervals[end][0] > start[1]:
                ans.append([start[0], max(start[1], intervals[end - 1][1])])
                start = intervals[min(end, n - 1)]
            else:
                start[1] = max(start[1], intervals[end][1])
            end += 1

        return ans
