package main

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	reverse := 0
	xcopy := x

	for xcopy > 0 {
		reverse = (reverse * 10) + (xcopy % 10)
		xcopy /= 10
	}

	return reverse == x
}
