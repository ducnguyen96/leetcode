from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        n = len(intervals)
        if n == 0:
            return [newInterval]

        ans: List[List[int]] = []
        idx = 0

        if newInterval[0] < intervals[0][0]:
            ans.append(newInterval)
        else:
            while idx < n and intervals[idx][0] <= newInterval[0]:
                ans.append(intervals[idx])
                idx += 1
            idx -= 1
            intervals[idx] = newInterval

        while idx < n:
            current = ans[-1]
            if intervals[idx][0] > current[1]:
                ans.append(intervals[idx])
            else:
                ans[-1][1] = max(current[1], intervals[idx][1])
            idx += 1

        return ans
