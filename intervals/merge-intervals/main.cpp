#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    if (n == 1) {
      return intervals;
    }

    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return b[0] > a[0]; });

    vector<vector<int>> ans;

    vector<int> start = {intervals[0][0], intervals[0][1]};
    int end = 1;

    while (end <= n) {
      if (end == n || intervals[end][0] > start[1]) {
        ans.push_back({start[0], max(start[1], intervals[end - 1][1])});
        start = intervals[min(end, n - 1)];
      } else {
        start[1] = max(start[1], intervals[end][1]);
      }
      end++;
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  // vector<vector<int>> intervals = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
  // vector<vector<int>> intervals = {{1, 4}, {2, 3}};
  vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};

  auto sol = new Solution();
  auto ans = sol->merge(intervals);

  // for (auto interval : ans) {
  //   cout << interval[0] << " " << interval[1] << endl;
  // }

  return 0;
}
