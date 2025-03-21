function isValid(s: string): boolean {
  const st = Array<string>(10000);
  let idx = -1;
  for (const ch of s) {
    if (ch === "(" || ch == "[" || ch == "{") {
      idx++;
      st[idx] = ch;
    } else if (idx === -1) {
      return false;
    } else if (
      (ch === ")" && st[idx] === "(") ||
      (ch === "]" && st[idx] === "[") ||
      (ch === "}" && st[idx] === "{")
    ) {
      idx--;
    } else {
      return false;
    }
  }
  return idx === -1;
}
