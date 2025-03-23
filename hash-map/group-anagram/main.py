from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 1:
            return [[strs[0]]]

        myMap= {}

        for word in strs:
            sortedWord = "".join(sorted(word)) 
            if sortedWord in myMap:
                myMap[sortedWord].append(word)
            else:
                myMap[sortedWord] = [word]

        ans = []

        for key in myMap:
            ans.append(myMap[key])

        return ans
