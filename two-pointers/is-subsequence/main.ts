function isSubsequence(s: string, t: string): boolean {
  const sLength = s.length;
  const tLength = t.length;
  if (sLength > tLength) return false;

  let [left, right] = [0, 0];
  while (right < tLength) {
    while (left < sLength && right < tLength && s[left] === t[right]) {
      left++;
      right++;
    }
    right++;
  }
  return left == sLength;
}
