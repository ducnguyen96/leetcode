function summaryRanges(nums: number[]): string[] {
  const rs: string[] = [];
  const n = nums.length;
  let start = 0;
  let end = 1;
  while (end <= n) {
    if (end === n || nums[end] > nums[end - 1] + 1) {
      const numStart = nums[start].toString();
      if (start === end - 1) {
        rs.push(numStart);
      } else {
        rs.push(numStart + "->" + nums[end - 1]);
      }
      start = end;
    }
    end++;
  }
  return rs;
}
