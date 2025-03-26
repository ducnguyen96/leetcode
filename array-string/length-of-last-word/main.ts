function lengthOfLastWord(s: string): number {
  let last = 0;
  let length = 0;

  for (const ch of s) {
    if (ch === " ") {
      if (length === 0) continue;
      last = length;
      length = 0;
    } else {
      length++;
    }
  }

  return length > 0 ? length : last;
}
