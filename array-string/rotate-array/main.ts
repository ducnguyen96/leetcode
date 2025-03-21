function rotate(nums: number[], k: number): void {
  const n = nums.length;
  const r = k % n;
  if (n == 1 || k == 0 || r == 0) return;

  let idx = 0;
  let prevIdx = idx;
  let prev = nums[prevIdx];

  for (let i = 0; i < n; i++) {
    idx += r;
    if (idx >= n) idx -= n;

    const tmp = nums[idx];
    nums[idx] = prev;
    prev = tmp;

    if (idx === prevIdx) {
      idx++;
      prevIdx = idx;
      prev = nums[prevIdx];
    }
  }
}
