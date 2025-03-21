package main

func longestNiceSubarray(nums []int) int {
	n := len(nums)

	left := 0
	right := 0

	maxLength := 0
	mask := 0
	for right < n {
		for (mask & nums[right]) != 0 {
			mask ^= nums[left]
			left++
		}
		mask |= nums[right]
		maxLength = max(maxLength, right-left+1)
		right++
	}
	return maxLength
}
