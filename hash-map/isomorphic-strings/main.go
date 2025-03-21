package main

import "fmt"

func isIsomorphic(s string, t string) bool {
	sMap := map[byte]byte{}
	for i := 0; i < len(s); i++ {
		sCh := s[i]
		tCh := t[i]
		if val, ok := sMap[sCh]; ok {
			if val != tCh {
				return false
			}
		} else {
			for _, v := range sMap {
				if v == tCh {
					return false
				}
			}
			sMap[sCh] = tCh
		}
	}
	return true
}

func main() {
	fmt.Println(isIsomorphic("foo", "bar"))
}
