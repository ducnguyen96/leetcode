function twoSum(nums: number[], target: number): number[] {
  const myMap = {};

  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    if (myMap[target - num] !== undefined) {
      return [myMap[target - num], i];
    } else {
      myMap[num] = i;
    }
  }
  return [];
}
