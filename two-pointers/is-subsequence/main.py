import sys
from typing import List


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        sLength = len(s)
        tLength = len(t)
        if sLength > tLength:
            return False

        left = 0
        right = 0
        while right < tLength:
            while left < sLength and right < tLength and s[left] == t[right]:
                left += 1
                right += 1
            right += 1

        return left == sLength


def main() -> int:
    solution = Solution()
    return 0
    solution.isSubsequence("abc", "adhbgc")


if __name__ == "__main__":
    sys.exit(main())
