function isIsomorphic(s: string, t: string): boolean {
  const sMap: Record<string, string> = {};
  for (let i = 0; i < s.length; i++) {
    const sCh = s[i];
    const tCh = t[i];
    if (sMap[sCh]) {
      if (sMap[sCh] !== tCh) return false;
    } else {
      if (Object.values(sMap).includes(tCh)) return false;
      sMap[sCh] = tCh;
    }
  }
  return true;
}
