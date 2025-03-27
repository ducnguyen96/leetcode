function mySqrt(x: number): number {
  let start = 1;
  let end = x;

  while (start <= end) {
    const mid = start + Math.floor((end - start) / 2);
    if (mid == x / mid) return mid;
    if (mid > x / mid) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return end;
}
