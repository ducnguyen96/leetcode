#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int n = rows * cols;

    vector<int> ans = {};

    int r = 0;
    int rs = 0;
    int re = rows - 1;

    int c = 0;
    int cs = 0;
    int ce = cols - 1;

    int direction = 1;

    for (int i = 0; i < n; i++) {
      ans.push_back(matrix[r][c]);
      switch (direction) {
      case 1: // increase col
        if (c == ce) {
          rs++;
          r = rs;
          direction = 2;
        } else {
          c++;
        }
        break;
      case 2: // increase row
        if (r == re) {
          ce--;
          c = ce;
          direction = 3;
        } else {
          r++;
        }
        break;
      case 3: // decrease col
        if (c == cs) {
          re--;
          r = re;
          direction = 4;
        } else {
          c--;
        }
        break;
      default: // decrease row
        if (r == rs) {
          cs++;
          ;
          c = cs;
          direction = 1;
        } else {
          r--;
        }
      }
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {

  auto sol = new Solution();

  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  auto ans = sol->spiralOrder(matrix);
  for (auto num : ans) {
    cout << num << " ";
  }

  return 0;
}
