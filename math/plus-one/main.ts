function plusOne(digits: number[]): number[] {
  let carry = 1;
  for (let i = digits.length - 1; i >= 0; i--) {
    const tmp = digits[i];
    digits[i] = (tmp + carry) % 10;
    carry = Math.floor((tmp + carry) / 10);
  }
  if (carry == 0) return digits;
  return [1, ...digits];
}
