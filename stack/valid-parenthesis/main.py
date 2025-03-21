class Solution:
    def isValid(self, s: str) -> bool:
        st = [""] * 10000
        idx = -1
        for ch in s:
            if ch == "(" or ch == "[" or ch == "{":
                idx += 1
                st[idx] = ch
            elif idx == -1:
                return False
            elif (
                (ch == ")" and st[idx] == "(")
                or (ch == "]" and st[idx] == "[")
                or (ch == "}" and st[idx] == "{")
            ):
                idx -= 1
            else:
                return False
        return idx == -1
