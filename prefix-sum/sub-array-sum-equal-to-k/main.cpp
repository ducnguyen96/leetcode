#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    int prefixSum = 0;
    int count = 0;
    unordered_map<int, int> prefixCount = {{0, 1}};

    for (int i = 0; i < n; i++) {
      prefixSum += nums[i];

      if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
        count += prefixCount[prefixSum - k];
      }

      prefixCount[prefixSum]++;
    }

    return count;
  }
};
