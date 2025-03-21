function maxProfit(prices: number[]): number {
  const n = prices.length;
  if (n < 2) return 0;
  let minPrice = prices[0];
  let profit = 0;
  for (let i = 1; i < n; i++) {
    if (prices[i - 1] < minPrice) minPrice = prices[i - 1];
    profit = Math.max(profit, prices[i] - minPrice);
  }
  return profit;
}
