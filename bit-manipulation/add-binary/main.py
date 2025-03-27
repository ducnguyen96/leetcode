class Solution:
    def addBinary(self, a: str, b: str) -> str:
        idxa = len(a) - 1
        idxb = len(b) - 1
        carry = 0

        rs = ""

        while idxa > -1 or idxb > -1 or carry:
            if idxa > -1:
                carry += int(a[idxa])
                idxa -= 1
            if idxb > -1:
                carry += int(b[idxb])
                idxb -= 1

            rs = str(carry % 2) + rs
            carry //= 2

        return rs
