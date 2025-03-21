class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        myMap = {}

        for ch in s:
            myMap[ch] = myMap.get(ch, 0) + 1

        for ch in t:
            if ch not in myMap or myMap[ch] == 0:
                return False
            myMap[ch] -= 1

        return True
