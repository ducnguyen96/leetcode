package main

func climbStairs(n int) int {
	cache := map[int]int{1: 1, 2: 2}

	var dp func(n int) int
	dp = func(n int) int {
		if _, ok := cache[n]; ok {
			return cache[n]
		}
		rs := dp(n-1) + dp(n-2)
		cache[n] = rs
		return rs
	}

	return dp(n)
}
