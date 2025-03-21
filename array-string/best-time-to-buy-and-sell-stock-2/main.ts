function maxProfit(prices: number[]): number {
  const n = prices.length;
  if (n < 2) return 0;

  let profit = 0;
  let minPrice = prices[0];
  for (let i = 1; i < n; i++) {
    if (prices[i - 1] < minPrice) {
      minPrice = prices[i - 1];
    }

    if (prices[i] - minPrice > 0) {
      profit += prices[i] - minPrice;
      minPrice = prices[i];
    }
  }

  return profit;
}
