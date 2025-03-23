function groupAnagrams(strs: string[]): string[][] {
  if (strs.length == 1) return [[strs[0]]];

  const myMap: Record<string, string[]> = {};

  for (const str of strs) {
    const sorted = str.split("").sort().join("");
    if (myMap[sorted]) {
      myMap[sorted].push(str);
    } else {
      myMap[sorted] = [str];
    }
  }

  return Object.values(myMap);
}
