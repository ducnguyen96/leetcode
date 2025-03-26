class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        last = 0
        length = 0

        for ch in s:
            if ch == " ":
                if length == 0:
                    continue
                last = length
                length = 0
            else:
                length += 1

        return length if length > 0 else last
