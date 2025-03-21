function subarraySum(nums: number[], k: number): number {
  let count = 0;
  let prefixSum = 0;
  let prefixCounts = { 0: 1 };

  for (const num of nums) {
    prefixSum += num;
    if (prefixCounts[prefixSum - k]) {
      count += prefixCounts[prefixSum - k];
    }
    prefixCounts[prefixSum] = (prefixCounts[prefixSum] ?? 0) + 1;
  }

  return count;
}
