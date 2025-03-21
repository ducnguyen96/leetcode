from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        result = []

        sLength = len(s)
        wordCount = len(words)
        wordLength = len(words[0])

        if sLength < wordCount * wordLength:
            return result

        wordFreq = {}
        for word in words:
            if word in wordFreq:
                wordFreq[word] += 1
            else:
                wordFreq[word] = 1

        # Try each possible starting point
        for i in range(wordLength):
            left = i
            right = i
            window = {}
            count = 0

            # Sliding window
            while right + wordLength <= sLength:
                word = s[right : right + wordLength]
                right += wordLength

                # not in words
                if word not in wordFreq:
                    count = 0
                    left = right
                    window.clear()
                else:
                    # in words
                    if word in window:
                        window[word] += 1
                    else:
                        window[word] = 1
                    count += 1

                    while window[word] > wordFreq[word]:
                        window[s[left : left + wordLength]] -= 1
                        left += wordLength
                        count -= 1

                    if count == wordCount:
                        result.append(left)
                        window[s[left : left + wordLength]] -= 1
                        count -= 1
                        left += wordLength

        return result
