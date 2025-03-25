package main

func twoSum(numbers []int, target int) []int {
	n := len(numbers)

	start, end := 0, 1

	for end < n && numbers[start]+numbers[end] < target {
		end++
	}

	if end == n {
		end--
	}

	for numbers[start]+numbers[end] != target {
		if numbers[start]+numbers[end] > target {
			end--
		} else {
			start++
		}
	}

	return []int{start + 1, end + 1}
}
