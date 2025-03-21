function isAnagram(s: string, t: string): boolean {
  if (s.length !== t.length) return false;

  const myMap = {};

  for (const ch of s) {
    myMap[ch] = myMap[ch] ? myMap[ch] + 1 : 1;
  }

  for (const ch of t) {
    if (!myMap[ch]) return false;
    myMap[ch]--;
  }

  return true;
}
