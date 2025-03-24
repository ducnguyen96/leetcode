function merge(intervals: number[][]): number[][] {
  const n = intervals.length;
  if (n === 1) return intervals;

  const sorted = intervals.sort((a, b) => a[0] - b[0]);
  const ans: number[][] = [];
  let start = sorted[0];
  let end = 1;
  while (end <= n) {
    if (end === n || sorted[end][0] > start[1]) {
      ans.push([start[0], Math.max(start[1], sorted[end - 1][1])]);
      start = intervals[Math.min(end, n - 1)];
    } else {
      start[1] = Math.max(start[1], sorted[end][1]);
    }
    end++;
  }

  return ans;
}
