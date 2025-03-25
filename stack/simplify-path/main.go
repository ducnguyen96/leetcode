package main

func simplifyPath(path string) string {
	n := len(path)

	stack := [3000]string{}
	idx := 0

	tmp := ""
	end := 0

	for end <= n {
		if end == n || path[end] == '/' {
			if tmp == ".." {
				if idx > 0 {
					idx--
				}
			} else if tmp != "" && tmp != "." {
				stack[idx] = "/" + tmp
				idx++
			}
			tmp = ""
		} else {
			tmp += string(path[end])
		}

		end++
	}

	ans := ""
	for i := 0; i < idx; i++ {
		ans += stack[i]
	}

	if len(ans) > 0 {
		return ans
	}
	return "/"
}
