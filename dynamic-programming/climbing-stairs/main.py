from typing import Dict


class Solution:
    cache: Dict = {1: 1, 2: 2}

    def climbStairs(self, n: int) -> int:
        if n in self.cache:
            return self.cache[n]

        rs = self.climbStairs(n - 1) + self.climbStairs(n - 2)
        self.cache[n] = rs

        return rs
