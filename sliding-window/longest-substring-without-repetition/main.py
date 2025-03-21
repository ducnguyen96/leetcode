import sys


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = len(s)
        if length < 2:
            return length
        left = 0
        right = 0
        longest = 0
        hashmap = {}

        while right < length:
            if s[right] not in hashmap or not hashmap[s[right]]:
                hashmap[s[right]] = True
                longest = max(longest, right - left + 1)
            else:
                while s[left] != s[right]:
                    hashmap[s[left]] = False
                    left += 1
                left += 1
            right += 1

        return longest


def main() -> int:
    solution = Solution()
    solution.lengthOfLongestSubstring("abcabcbb")
    return 0


if __name__ == "__main__":
    sys.exit(main())
