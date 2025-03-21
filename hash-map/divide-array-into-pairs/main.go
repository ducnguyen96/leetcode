package main

func divideArray(nums []int) bool {
	countTable := map[int]int{}
	for _, num := range nums {
		countTable[num]++
	}
	for _, val := range countTable {
		if val%2 != 0 {
			return false
		}
	}
	return true
}
