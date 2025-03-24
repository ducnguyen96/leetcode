package main

func insert(intervals [][]int, newInterval []int) [][]int {
	n := len(intervals)
	if n == 0 {
		return [][]int{newInterval}
	}

	ans := [][]int{}
	idx := 0

	if newInterval[0] < intervals[0][0] {
		ans = append(ans, newInterval)
	} else {
		for idx < n && intervals[idx][0] <= newInterval[0] {
			ans = append(ans, intervals[idx])
			idx++
		}
		idx--
		intervals[idx] = newInterval
	}

	for idx < n {
		current := ans[len(ans)-1]
		if intervals[idx][0] > current[1] {
			ans = append(ans, intervals[idx])
		} else {
			ans[len(ans)-1][1] = max(current[1], intervals[idx][1])
		}
		idx++
	}

	return ans
}
