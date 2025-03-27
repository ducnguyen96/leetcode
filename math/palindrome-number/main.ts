function isPalindrome(x: number): boolean {
  if (x < 0) return false;

  let reverse = 0;
  let xcopy = x;

  while (xcopy > 0) {
    reverse = reverse * 10 + (xcopy % 10);
    xcopy = Math.floor(xcopy / 10);
  }

  return reverse == x;
}
