function romanToInt(s: string): number {
  const myMap = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };

  const n = s.length;
  let sum = 0;
  let idx = 0;

  while (idx < n) {
    if (idx == n - 1 || myMap[s[idx]] >= myMap[s[idx + 1]]) {
      sum += myMap[s[idx]];
    } else {
      sum -= myMap[s[idx]];
      sum += myMap[s[idx + 1]];
      idx++;
    }

    idx++;
  }
  return sum;
}
