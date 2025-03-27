package main

func plusOne(digits []int) []int {
	carry := 1

	for i := len(digits) - 1; i >= 0; i-- {
		tmp := digits[i]
		digits[i] = (digits[i] + carry) % 10
		carry = (tmp + carry) / 10
	}

	if carry == 0 {
		return digits
	}

	return append([]int{1}, digits...)
}
