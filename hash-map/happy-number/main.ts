function isHappy(n: number): boolean {
  const myMap = { 1: true };
  let current = n;
  while (!myMap[current]) {
    myMap[current] = true;
    let sum = 0;
    while (current >= 10) {
      const tmp = current % 10;
      sum += tmp * tmp;
      current = Math.floor(current / 10);
    }
    sum += current * current;
    current = sum;
  }
  return current == 1;
}
