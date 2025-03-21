#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    int k = 0;
    int duplicates = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[k]) {
        k++;
        nums[k] = nums[i];
        duplicates = 1;
      } else if (duplicates < 2) {
        k++;
        nums[k] = nums[i];
        duplicates++;
      }
    }
    k++;
    return k;
  }
};
