package main

func longestConsecutive(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}

	myMap := map[int]bool{}
	for _, num := range nums {
		myMap[num] = true
	}

	longest := 1

	for num := range myMap {
		if _, ok := myMap[num-1]; !ok {
			current := num
			count := 1
			for myMap[current+1] {
				count++
				current++
			}
			longest = max(longest, count)
		}
	}
	return longest
}
