#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, vector<int>> myMap;
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (myMap.find(num) != myMap.end()) {
        if (i - myMap[num][myMap[num].size() - 1] <= k) {
          return true;
        } else {
          myMap[num].push_back(i);
        }
      } else {
        myMap[num].push_back(i);
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 1, 2, 3};
  auto sol = new Solution();
  sol->containsNearbyDuplicate(nums, 2);
  return 0;
}
