#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int k = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[k]) {
        k++;
        nums[k] = nums[i];
      }
    }
    k++;
    return k;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  auto rs = solution->removeDuplicates(nums);
  cout << rs << endl;

  return 0;
}
