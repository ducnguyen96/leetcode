function longestCommonPrefix(strs: string[]): string {
  if (strs.length === 1) return strs[0];

  let common = "";
  let idx = 0;

  for (const ch of strs[0]) {
    for (let i = 1; i < strs.length; i++) {
      if (idx === strs[i].length) return common;
      if (strs[i][idx] !== ch) return common;
    }
    common += ch;
    idx++;
  }
  return common;
}
