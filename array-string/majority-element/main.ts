function majorityElement(nums: number[]): number {
  let major = 0;
  let dup = 0;
  for (const num of nums) {
    if (dup === 0) {
      major = num;
    }
    dup += num === major ? 1 : -1;
  }
  return major;
}
