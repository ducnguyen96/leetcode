package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	length := len(s)
	if length < 2 {
		return length
	}
	str := []rune(s)
	left, right, longest := 0, 0, 0
	hashmap := make(map[rune]bool)
	for right < length {
		if !hashmap[str[right]] {
			hashmap[str[right]] = true
			longest = max(longest, right-left+1)
		} else {
			for str[left] != str[right] {
				hashmap[str[left]] = false
				left++
			}
			left++
		}
		right++
	}
	return longest
}

func main() {
	rs := lengthOfLongestSubstring("abcabcbb")
	fmt.Println(rs)
}
