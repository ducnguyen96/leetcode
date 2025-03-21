package main

func rotate(nums []int, k int) {
	n := len(nums)
	r := k % n
	if n == 1 || k == 0 || r == 0 {
		return
	}
	idx := 0
	prevIdx := idx
	prev := nums[prevIdx]
	for i := 0; i < n; i++ {
		idx += r
		if idx >= n {
			idx -= n
		}
		tmp := nums[idx]
		nums[idx] = prev
		prev = tmp

		if idx == prevIdx {
			idx++
			prevIdx = idx
			prev = nums[prevIdx]
		}
	}
}
