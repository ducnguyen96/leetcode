#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    int r = k % n;
    if (n == 1 || k == 0 || r == 0) {
      return;
    }
    int idx = 0;
    int prevIdx = idx;
    int prev = nums[idx];
    for (int i = 0; i < n; i++) {
      idx += r;
      if (idx >= n) {
        idx -= n;
      }

      int tmp = nums[idx];
      nums[idx] = prev;
      prev = tmp;

      if (idx == prevIdx) {
        idx++;
        prevIdx = idx;
        prev = nums[idx];
      }
    }
  }
};
;
