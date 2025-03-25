package main

func maxArea(height []int) int {
	n := len(height)
	start, end := 0, n-1
	area := 0
	for start < end {
		area = max(area, (end-start)*min(height[start], height[end]))
		if height[start] > height[end] {
			end--
		} else {
			start++
		}
	}
	return area
}
