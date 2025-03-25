function threeSum(nums: number[]): number[][] {
  const n = nums.length;

  nums.sort((a, b) => a - b);

  const ans: number[][] = [];
  let prev = -nums[0] - 1;

  for (let i = 0; i < n - 2; i++) {
    const target = -nums[i];
    if (target == prev) continue;
    prev = target;

    let [start, end] = [i + 1, n - 1];
    while (start < end) {
      const sum = nums[start] + nums[end];
      if (sum == target) {
        ans.push([-target, nums[start], nums[end]]);
        const currentStart = nums[start];
        const currentEnd = nums[end];
        while (nums[start] == currentStart && start < end) {
          start++;
        }
        while (nums[end] == currentEnd && start < end) {
          end--;
        }
      } else if (sum > target) {
        end--;
      } else {
        start++;
      }
    }
  }

  return ans;
}
