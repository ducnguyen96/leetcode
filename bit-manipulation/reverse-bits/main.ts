function reverseBits(n: number): number {
  let ans = 0;
  for (let i = 0; i < 32; i++) {
    ans <<= 1;
    if (n & 1) ans |= 1;
    n >>= 1;
  }
  return ans >>> 0;
}
