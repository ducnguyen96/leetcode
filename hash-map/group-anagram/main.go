package main

import "sort"

func sortStringASCII(s string) string {
	bytes := []byte(s)
	sort.Slice(bytes, func(i, j int) bool {
		return bytes[i] < bytes[j]
	})
	return string(bytes)
}

func groupAnagrams(strs []string) [][]string {
	if len(strs) == 1 {
		return [][]string{{strs[0]}}
	}
	myMap := map[string][]string{}

	for _, str := range strs {
		sorted := sortStringASCII(str)
		if _, ok := myMap[sorted]; ok {
			myMap[sorted] = append(myMap[sorted], str)
		} else {
			myMap[sorted] = []string{str}
		}
	}

	ans := [][]string{}

	for _, v := range myMap {
		ans = append(ans, v)
	}

	return ans
}
