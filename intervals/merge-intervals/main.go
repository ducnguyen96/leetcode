package main

import "sort"

func merge(intervals [][]int) [][]int {
	n := len(intervals)
	if n == 1 {
		return intervals
	}

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	ans := [][]int{}

	start := intervals[0]
	end := 1

	for end <= n {
		if end == n || intervals[end][0] > start[1] {
			ans = append(ans, []int{start[0], max(start[1], intervals[end-1][1])})
			start = intervals[min(end, n-1)]
		} else {
			start[1] = max(start[1], intervals[end][1])
		}
		end++
	}

	return ans
}
