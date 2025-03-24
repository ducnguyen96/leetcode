function longestConsecutive(nums: number[]): number {
  if (nums.length < 2) return nums.length;

  let longest = 1;
  const mySet = new Set(nums);
  for (const num of mySet) {
    if (!mySet.has(num - 1)) {
      let current = num;
      let count = 1;
      while (mySet.has(current + 1)) {
        count++;
        current++;
      }
      longest = Math.max(longest, count);
    }
  }
  return longest;
}
