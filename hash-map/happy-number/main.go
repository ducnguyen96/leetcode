package main

func isHappy(n int) bool {
	myMap := map[int]bool{1: true}
	current := n
	for !myMap[current] {
		myMap[current] = true
		sum := 0
		for current >= 10 {
			tmp := current % 10
			sum += tmp * tmp
			current /= 10
		}
		sum += current * current
		current = sum
	}
	return current == 1
}
