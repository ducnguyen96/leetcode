package main

import "fmt"

func addBinary(a string, b string) string {
	rs := ""

	idxa := len(a) - 1
	idxb := len(b) - 1
	carry := 0

	for idxa > -1 || idxb > -1 || carry > 0 {
		if idxa > -1 {
			carry += int(a[idxa] - '0')
			idxa--
		}
		if idxb > -1 {
			carry += int(b[idxb] - '0')
			idxb--
		}

		ch := carry%2 + '0'
		carry /= 2

		rs = string(ch) + rs
	}

	return rs
}

func main() {
	rs := addBinary("11", "1")
	fmt.Println(rs)
}
