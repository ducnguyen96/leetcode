function wordPattern(pattern: string, s: string): boolean {
  const myMap: Record<string, string> = {};
  const pSize = pattern.length;
  const sSize = s.length;

  let [left, right] = [0, 0];

  for (let i = 0; i < pSize; i++) {
    const ch = pattern[i];

    while (true) {
      if (right == sSize || s[right] == " ") break;
      right++;
    }

    if (right == sSize && i < pSize - 1) return false;

    const word = s.slice(left, right);

    if (myMap[ch]) {
      if (myMap[ch] !== word) return false;
    } else {
      for (const key in myMap) {
        if (myMap[key] === word) return false;
      }
      myMap[ch] = word;
    }
    right++;
    left = right;
  }
  return right === sSize + 1;
}
