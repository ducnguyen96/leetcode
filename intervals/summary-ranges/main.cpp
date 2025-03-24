#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> rs = {};
    int n = nums.size();
    int start = 0;
    int end = 1;
    while (end <= n) {
      if (end == n || nums[end] > nums[end - 1] + 1) {
        string num_start = to_string(nums[start]);
        if (start == end - 1) {
          rs.insert(rs.end(), num_start);
        } else {
          rs.insert(rs.end(), num_start + "->" + to_string(nums[end - 1]));
        }
        start = end;
      }
      end++;
    }

    return rs;
  }
};
