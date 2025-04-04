from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        start, end = 0, 1
        while end < n and numbers[start] + numbers[end] < target:
            end += 1
        if end == n:
            end -= 1
        while numbers[start] + numbers[end] != target:
            if numbers[start] + numbers[end] > target:
                end -= 1
            else:
                start += 1
        return [start+1, end+1]

