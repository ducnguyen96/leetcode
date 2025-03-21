package main

func removeDuplicates(nums []int) int {
	n := len(nums)
	k := 0
	dup := 1
	for i := 1; i < n; i++ {
		if nums[i] != nums[k] {
			k++
			nums[k] = nums[i]
			dup = 1
		} else if dup < 2 {
			k++
			nums[k] = nums[i]
			dup++
		}
	}
	return k
}
