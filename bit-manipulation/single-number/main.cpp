#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int mask = 0;
    for (auto num : nums) {
      mask ^= num;
    }
    return mask;
  }
};
