package main

import "fmt"

func removeDuplicates(nums []int) int {
	k := 0
	for i, v := range nums {
		if nums[k] != v {
			k++
			nums[k] = nums[i]
		}
	}
	k++
	return k
}

func main() {
	nums := []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
	rs := removeDuplicates(nums)
	fmt.Println(rs)
}
