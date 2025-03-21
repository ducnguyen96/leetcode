class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        sMap = {}
        for i in range(len(s)):
            sCh = s[i]
            tCh = t[i]
            if sCh in sMap:
                if sMap[sCh] != tCh:
                    return False
            else:
                if tCh in sMap.values():
                    return False
                sMap[sCh] = tCh
        return True
