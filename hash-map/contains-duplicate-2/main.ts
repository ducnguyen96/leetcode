function containsNearbyDuplicate(nums: number[], k: number): boolean {
  const myMap = {};
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    if (myMap[num] != undefined) {
      if (i - myMap[num][myMap[num].length - 1] <= k) {
        return true;
      } else {
        myMap[num].push(i);
      }
    } else {
      myMap[num] = [i];
    }
  }
  return false;
}
