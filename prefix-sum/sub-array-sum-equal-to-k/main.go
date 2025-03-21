package main

func subarraySum(nums []int, k int) int {
	prefixSum := 0
	prefixCounts := map[int]int{0: 1}
	count := 0

	for _, num := range nums {
		prefixSum += num
		if _, ok := prefixCounts[prefixSum-k]; ok {
			count += prefixCounts[prefixSum-k]
		}
		prefixCounts[prefixSum]++
	}

	return count
}
