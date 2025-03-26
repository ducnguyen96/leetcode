package main

func longestCommonPrefix(strs []string) string {
	if len(strs) == 1 {
		return strs[0]
	}

	common := ""
	idx := 0

	for _, v := range strs[0] {
		for i := 1; i < len(strs); i++ {
			if idx == len(strs[i]) {
				return common
			}
			if strs[i][idx] != byte(v) {
				return common
			}
		}
		common += string(v)
		idx++
	}

	return common
}
