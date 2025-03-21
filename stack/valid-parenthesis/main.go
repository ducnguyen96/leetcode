package main

import "fmt"

func isValid(s string) bool {
	st := [10000]rune{}
	idx := -1

	for _, v := range s {
		if v == '(' || v == '[' || v == '{' {
			idx++
			st[idx] = v
		} else if idx == -1 {
			return false
		} else if (v == ')' && st[idx] == '(') || (v == ']' && st[idx] == '[') || (v == '}' && st[idx] == '{') {
			idx--
		} else {
			return false
		}
	}

	return idx == -1
}

func main() {
	fmt.Println(isValid("()"))
}
