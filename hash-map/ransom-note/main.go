package main

func canConstruct(ransomNote string, magazine string) bool {
	if len(magazine) < len(ransomNote) {
		return false
	}

	count := make(map[rune]int)
	for _, ch := range magazine {
		count[ch]++
	}

	for _, ch := range ransomNote {
		if count[ch] == 0 {
			return false
		}
		count[ch]--
	}

	return true
}
