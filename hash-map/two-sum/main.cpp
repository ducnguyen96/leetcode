#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> myMap;

    for (int i = 0; i < nums.size(); i++) {
      if (myMap.find(target - nums[i]) != myMap.end()) {
        return {myMap[target - nums[i]], i};
      } else {
        myMap[nums[i]] = i;
      }
    }

    return {};
  }
};
