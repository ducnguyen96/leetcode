#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();
    if (n == 0) {
      return {newInterval};
    }

    vector<vector<int>> ans;
    int idx = 0;

    if (newInterval[0] < intervals[0][0]) {
      ans.push_back(newInterval);
    } else {
      while (idx < n && intervals[idx][0] <= newInterval[0]) {
        ans.push_back(intervals[idx]);
        idx++;
      }
      idx--;
      intervals[idx] = newInterval;
    }

    while (idx < n) {
      auto current = ans[ans.size() - 1];
      if (intervals[idx][0] > current[1]) {
        ans.push_back(intervals[idx]);
      } else {
        ans[ans.size() - 1][1] = max(current[1], intervals[idx][1]);
      }
      idx++;
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();
  // vector<vector<int>> intervals = {{1, 5}};
  // vector<int> newInterval = {6, 8};

  vector<vector<int>> intervals = {{1, 5}};
  vector<int> newInterval = {1, 7};

  // vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  // vector<int> newInterval = {2, 5};

  // vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12,
  // 16}}; vector<int> newInterval = {4, 8};

  // vector<vector<int>> intervals = {{0, 5}, {9, 12}};
  // vector<int> newInterval = {7, 16};

  // vector<vector<int>> intervals = {{1, 5}};
  // vector<int> newInterval = {2, 3};

  auto ans = sol->insert(intervals, newInterval);

  for (auto a : ans) {
    cout << a[0] << " " << a[1] << endl;
  }

  return 0;
}
