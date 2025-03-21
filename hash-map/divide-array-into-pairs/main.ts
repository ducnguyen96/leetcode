function divideArray(nums: number[]): boolean {
  const countTable: Record<number, number> = {};

  for (const num of nums) {
    countTable[num] = (countTable[num] || 0) + 1;
  }

  for (const val of Object.values(countTable)) {
    if (val % 2 !== 0) {
      return false;
    }
  }

  return true;
}
