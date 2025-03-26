from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]

        common = ""
        idx = 0

        for ch in strs[0]:
            for i in range(1, len(strs)):
                if idx == len(strs[i]):
                    return common
                if strs[i][idx] != ch:
                    return common
            common += ch
            idx += 1

        return common
