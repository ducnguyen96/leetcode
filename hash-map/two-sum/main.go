package main

func twoSum(nums []int, target int) []int {
	myMap := map[int]int{}

	for idx, num := range nums {
		if _, ok := myMap[target-num]; ok {
			return []int{myMap[target-num], idx}
		} else {
			myMap[num] = idx
		}
	}

	return []int{}
}
