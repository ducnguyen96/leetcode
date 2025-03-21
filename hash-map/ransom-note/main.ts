function canConstruct(ransomNote: string, magazine: string): boolean {
  const count = {};
  for (const ch of magazine) {
    count[ch] = count[ch] ? count[ch] + 1 : 1;
  }
  for (const ch of ransomNote) {
    if (!count[ch]) return false;
    count[ch]--;
  }
  return true;
}
