function lengthOfLongestSubstring(s: string): number {
  const len = s.length;
  if (len < 2) return len;

  let [left, right, longest] = [0, 0, 0];
  const hashmap = {};
  while (right < len) {
    if (!hashmap[s[right]]) {
      hashmap[s[right]] = true;
      longest = Math.max(longest, right - left + 1);
    } else {
      while (s[right] !== s[left]) {
        hashmap[s[left]] = false;
        left++;
      }
      left++;
    }
    right++;
  }
  return longest;
}
