function climbStairs(n: number): number {
  const cache: Record<number, number> = { 1: 1, 2: 2 };

  const dp = (n: number): number => {
    if (cache[n]) return cache[n];
    const rs = dp(n - 1) + dp(n - 2);
    cache[n] = rs;
    return rs;
  };

  return dp(n);
}
