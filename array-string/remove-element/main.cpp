#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[k] = nums[i];
        k++;
      }
    }
    for (auto num : nums) {
      cout << num << ", ";
    }
    return k;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  auto solution = new Solution();
  solution->removeElement(nums, 2);
  return 0;
}
