#include <vector>
using namespace std;

class Solution {
public:
  int longestNiceSubarray(vector<int> &nums) {
    int n = nums.size();

    int left = 0;
    int right = 0;

    int maxLength = 0;
    int mask = 0;
    while (right < n) {
      while ((mask & nums[right]) != 0) {
        mask ^= nums[left];
        left++;
      }
      mask |= nums[right];
      maxLength = std::max(maxLength, right - left + 1);
      right++;
    }

    return maxLength;
  };
};
