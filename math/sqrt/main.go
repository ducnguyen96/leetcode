package main

func mySqrt(x int) int {
	start := 1
	end := x

	for start <= end {
		mid := start + (end-start)/2
		if mid == x/mid {
			return mid
		} else if mid > x/mid {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	return end
}
