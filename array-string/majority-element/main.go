package main

func majorityElement(nums []int) int {
	major := 0
	dup := 0
	for _, num := range nums {
		if dup == 0 {
			major = num
		}

		if num == major {
			dup += 1
		} else {
			dup -= 1
		}
	}

	return major
}
