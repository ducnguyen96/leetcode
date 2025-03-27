from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for i, v in reversed(list(enumerate(digits))):
            digits[i] = (v + carry) % 10
            carry = (v + carry) // 10
        if carry == 0:
            return digits
        return [1] + digits
