#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool divideArray(vector<int> &nums) {
    unordered_map<int, int> countTable = {};
    for (auto num : nums) {
      countTable[num]++;
    }
    for (auto pair : countTable) {
      if (pair.second % 2 != 0) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  vector<int> nums = {3, 2, 3, 2, 2, 2};
  auto rs = solution->divideArray(nums);
  cout << rs << endl;

  return 0;
}
