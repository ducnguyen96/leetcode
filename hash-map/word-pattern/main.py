class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        myMap = {}
        pSize = len(pattern)
        sSize = len(s)

        left = 0
        right = 0

        for i in range(pSize):
            ch = pattern[i]

            while True:
                if right == sSize or s[right] == " ":
                    break
                right += 1

            if right == sSize and i < pSize - 1:
                return False

            word = s[left:right]

            if ch in myMap:
                if myMap[ch] != word:
                    return False
            else:
                for key in myMap:
                    if myMap[key] == word:
                        return False
                myMap[ch] = word
            right += 1
            left = right

        return right == sSize + 1


if __name__ == "__main__":
    sol = Solution()
    sol.wordPattern("abba", "dog cat cat dog")
