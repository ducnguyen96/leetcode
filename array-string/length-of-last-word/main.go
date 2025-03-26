package main

func lengthOfLastWord(s string) int {
	last := 0
	length := 0

	for _, v := range s {
		if v == ' ' {
			if length == 0 {
				continue
			}
			last = length
			length = 0
		} else {
			length++
		}
	}
	if length > 0 {
		return length
	}
	return last
}
