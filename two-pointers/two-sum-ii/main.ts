function twoSum(numbers: number[], target: number): number[] {
  const n = numbers.length;

  let [start, end] = [0, 1];

  while (end < n && numbers[start] + numbers[end] < target) {
    end++;
  }

  if (end == n) end--;

  while (numbers[start] + numbers[end] != target) {
    if (numbers[start] + numbers[end] > target) {
      end--;
    } else {
      start++;
    }
  }

  return [start + 1, end + 1];
}
