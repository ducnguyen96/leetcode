#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int res = 0;
    int majority = 0;

    for (int n : nums) {
      if (majority == 0) {
        res = n;
      }

      majority += n == res ? 1 : -1;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  auto s = new Solution();
  vector<int> nums = {2, 1, 2, 3, 2, 5};
  auto res = s->majorityElement(nums);
  cout << res;
  return 0;
}
