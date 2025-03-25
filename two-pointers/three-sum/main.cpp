#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    auto n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int prev = -nums[0] - 1;

    for (int i = 0; i < n - 2; i++) {
      int target = -nums[i];

      if (target == prev) {
        continue;
      }
      prev = target;

      int start = i + 1;
      int end = n - 1;
      while (start < end) {
        int sum = nums[start] + nums[end];
        if (sum == target) {
          ans.push_back({-target, nums[start], nums[end]});
          int currentStart = nums[start];
          int currentEnd = nums[end];
          while (nums[start] == currentStart && start < end) {
            start++;
          }
          while (nums[end] == currentEnd && start < end) {
            end--;
          }
        } else if (sum > target) {
          end--;
        } else {
          start++;
        }
      }
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  // vector<int> nums = {-1, 0, 1, 2, -1, -4};
  // vector<int> nums = {0, 0, 0};
  // vector<int> nums = {0, 1, 1};
  // vector<int> nums = {-2, 0, 1, 1, 2};
  vector<int> nums = {2,  -3, 0, -2, -5, -5, -4, 1,  2,
                      -2, 2,  0, 2,  -4, 5,  5,  -10};
  auto ans = sol->threeSum(nums);
  for (auto aaa : ans) {
    cout << aaa[0] << " " << aaa[1] << " " << aaa[2] << endl;
  }
  return 0;
}
