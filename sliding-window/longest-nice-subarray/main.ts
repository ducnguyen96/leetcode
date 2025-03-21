function longestNiceSubarray(nums: number[]): number {
  const n = nums.length;

  let [left, right] = [0, 0];
  let maxLength = 0;
  let mask = 0;
  while (right < n) {
    while ((mask & nums[right]) !== 0) {
      mask ^= nums[left];
      left++;
    }
    mask |= nums[right];
    maxLength = Math.max(maxLength, right - left + 1);
    right++;
  }
  return maxLength;
}
