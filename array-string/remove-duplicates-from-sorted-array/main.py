import sys
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        for value in nums:
            if nums[k] != value:
                k += 1
                nums[k] = value
        k += 1
        return k


def main() -> int:
    solution = Solution()
    solution.removeDuplicates([0, 1, 2, 2, 3, 0, 4, 2])
    return 0


if __name__ == "__main__":
    sys.exit(main())
