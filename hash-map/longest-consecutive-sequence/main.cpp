#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return n;
    }

    int longest = 1;
    unordered_set<int> mySet(nums.begin(), nums.end());

    for (auto num : mySet) {
      if (mySet.find(num - 1) == mySet.end()) {
        int currentNum = num;
        int count = 1;

        while (mySet.find(currentNum + 1) != mySet.end()) {
          count++;
          currentNum++;
        }

        longest = max(longest, count);
      }
    }

    return longest;
  }
};
