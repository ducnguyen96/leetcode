function addBinary(a: string, b: string): string {
  let idxa = a.length - 1;
  let idxb = b.length - 1;
  let carry = 0;

  let rs = "";

  while (idxa > -1 || idxb > -1 || carry) {
    if (idxa > -1) carry += Number(a[idxa--]);
    if (idxb > -1) carry += Number(b[idxb--]);

    rs = (carry % 2) + rs;
    carry = Math.floor(carry / 2);
  }

  return rs;
}
