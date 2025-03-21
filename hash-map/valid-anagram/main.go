package main

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	myMap := map[byte]int{}

	for i := 0; i < len(s); i++ {
		myMap[s[i]]++
		myMap[t[i]]--
	}

	for _, v := range myMap {
		if v != 0 {
			return false
		}
	}
	return true
}
