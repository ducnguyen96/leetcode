function insert(intervals: number[][], newInterval: number[]): number[][] {
  const n = intervals.length;
  if (n === 0) {
    return [newInterval];
  }

  const ans: number[][] = [];
  let idx = 0;
  if (newInterval[0] < intervals[0][0]) {
    ans.push(newInterval);
  } else {
    while (idx < n && intervals[idx][0] <= newInterval[0]) {
      ans.push(intervals[idx]);
      idx++;
    }
    idx--;
    intervals[idx] = newInterval;
  }

  while (idx < n) {
    const current = ans[ans.length - 1];
    if (intervals[idx][0] > current[1]) {
      ans.push(intervals[idx]);
    } else {
      ans[ans.length - 1][1] = Math.max(current[1], intervals[idx][1]);
    }
    idx++;
  }

  return ans;
}
