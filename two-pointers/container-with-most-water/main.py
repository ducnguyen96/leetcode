from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        start,end = 0, len(height) - 1
        area = 0
        while start < end:
            area = max(area, (end-start)*min(height[start], height[end]))
            if height[start] >  height[end]:
                end -= 1
            else:
                start += 1
        return area
