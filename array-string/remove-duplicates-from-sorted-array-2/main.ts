function removeDuplicates(nums: number[]): number {
  let k = 0;
  let dup = 1;
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] !== nums[k]) {
      k++;
      nums[k] = nums[i];
      dup = 1;
    } else if (dup < 2) {
      k++;
      nums[k] = nums[i];
      dup++;
    }
  }
  k++;
  return k;
}
