package main

import "strconv"

func summaryRanges(nums []int) []string {
	rs := []string{}
	n := len(nums)
	start := 0
	end := 1
	for end <= n {
		if end == n || nums[end] > nums[end-1]+1 {
			numStart := strconv.Itoa(nums[start])
			if start == end-1 {
				rs = append(rs, numStart)
			} else {
				rs = append(rs, numStart+"->"+strconv.Itoa(nums[end-1]))
			}
			start = end
		}
		end++
	}
	return rs
}
