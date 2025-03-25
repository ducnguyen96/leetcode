package main

import "sort"

func threeSum(nums []int) [][]int {
	n := len(nums)

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	ans := [][]int{}
	prev := -nums[0] - 1

	for i := range n - 2 {
		target := -nums[i]
		if target == prev {
			continue
		}
		prev = target

		start := i + 1
		end := n - 1

		for start < end {
			sum := nums[start] + nums[end]
			if sum == target {
				ans = append(ans, []int{-target, nums[start], nums[end]})
				currentStart := nums[start]
				currentEnd := nums[end]
				for nums[start] == currentStart && start < end {
					start++
				}
				for nums[end] == currentEnd && start < end {
					end--
				}
			} else if sum > target {
				end--
			} else {
				start++
			}
		}
	}
	return ans
}
