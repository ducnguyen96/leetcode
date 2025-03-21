package main

import "fmt"

func isSubsequence(s string, t string) bool {
	sLength := len(s)
	tLength := len(t)
	if sLength > tLength {
		return false
	}

	left, right := 0, 0
	for right < tLength {
		for left < sLength && s[left] == t[right] {
			left++
			right++
		}
		right++
	}
	return left == sLength
}

func main() {
	rs := isSubsequence("acb", "ahbgdc")
	fmt.Println(rs)
}
