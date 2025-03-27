function minOperations(nums: number[]): number {
  let count = 0;
  let n = nums.length;
  for (let i = 0; i < n - 2; i++) {
    if (nums[i] === 0) {
      nums[i] = 1;
      nums[i + 1] ^= 1;
      nums[i + 2] ^= 1;
      count++;
    }
  }
  return nums[n - 2] == 0 || nums[n - 1] == 0 ? -1 : count;
}
