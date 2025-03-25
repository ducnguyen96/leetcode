function maxArea(height: number[]): number {
  let [start, end] = [0, height.length - 1];
  let area = 0;
  while (start < end) {
    area = Math.max(area, (end - start) * Math.min(height[start], height[end]));
    if (height[start] > height[end]) {
      end--;
    } else {
      start++;
    }
  }
  return area;
}
