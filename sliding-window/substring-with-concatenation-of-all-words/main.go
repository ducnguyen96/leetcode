package main

func findSubstring(s string, words []string) []int {
	result := []int{}

	sLength := len(s)
	wordCount := len(words)
	wordLength := len(words[0])

	if sLength < wordCount*wordLength {
		return result
	}

	wordFreq := make(map[string]int)
	for _, word := range words {
		wordFreq[word]++
	}

	// Try each possible starting point
	for i := 0; i < wordLength; i++ {
		left, right := i, i
		count := 0
		window := make(map[string]int)

		// Sliding window
		for right+wordLength <= sLength {
			word := s[right : right+wordLength]
			right += wordLength

			// not in words
			if _, ok := wordFreq[word]; !ok {
				count = 0
				left = right
				window = make(map[string]int)
				// in words
			} else {
				window[word]++
				count++

				// remove exceed words
				for window[word] > wordFreq[word] {
					window[s[left:left+wordLength]]--
					left += wordLength
					count--
				}

				// find a result
				if count == wordCount {
					result = append(result, left)
					window[s[left:left+wordLength]]--
					count--
					left += wordLength
				}
			}
		}
	}

	return result
}
