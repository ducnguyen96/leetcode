package main

func containsNearbyDuplicate(nums []int, k int) bool {
	myMap := map[int][]int{}

	for idx, num := range nums {
		indices := myMap[num]
		if len(indices) > 0 {
			if idx-indices[len(indices)-1] <= k {
				return true
			} else {
				myMap[num] = append(indices, idx)
			}
		} else {
			myMap[num] = []int{idx}
		}
	}

	return false
}

func main() {
	containsNearbyDuplicate([]int{1, 0, 1, 1}, 1)
}
