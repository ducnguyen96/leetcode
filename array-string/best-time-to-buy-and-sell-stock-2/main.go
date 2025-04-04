package main

func maxProfit(prices []int) int {
	n := len(prices)
	if n < 2 {
		return 0
	}

	profit := 0
	minPrice := prices[0]

	for i := 1; i < n; i++ {
		if prices[i-1] < minPrice {
			minPrice = prices[i-1]
		}
		if prices[i]-minPrice > 0 {
			profit += prices[i] - minPrice
			minPrice = prices[i]
		}
	}

	return profit
}
