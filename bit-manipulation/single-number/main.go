package main

func singleNumber(nums []int) int {
	mask := 0
	for _, num := range nums {
		mask ^= num
	}
	return mask
}
