package main

func wordPattern(pattern string, s string) bool {
	myMap := map[byte]string{}
	pSize := len(pattern)
	sSize := len(s)

	left, right := 0, 0

	for i := 0; i < pSize; i++ {
		ch := pattern[i]

		for true {
			if right == sSize || s[right] == ' ' {
				break
			}
			right++
		}

		if right == sSize && i < pSize-1 {
			return false
		}

		word := s[left:right]
		if value, ok := myMap[ch]; ok {
			if value != word {
				return false
			}
		} else {
			for _, v := range myMap {
				if v == word {
					return false
				}
			}
			myMap[ch] = word
		}
		right++
		left = right
	}

	return right == sSize+1
}

func main() {
	wordPattern("abba", "dog cat cat dog")
}
