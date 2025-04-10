#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
  vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
  int numIslands(vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int ans = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '0') {
          continue;
        }
        ans++;
        dfs(grid, rows, cols, i, j);
      }
    }

    return ans;
  }

  void dfs(vector<vector<char>> &grid, int rows, int cols, int row, int col) {
    if (row < 0 || col < 0 || row >= rows || col >= cols ||
        grid[row][col] == '0') {
      return;
    }
    grid[row][col] = '0';
    dfs(grid, rows, cols, row - 1, col);
    dfs(grid, rows, cols, row + 1, col);
    dfs(grid, rows, cols, row, col - 1);
    dfs(grid, rows, cols, row, col + 1);
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  vector<vector<char>> grid = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
  };

  auto ans = sol->numIslands(grid);

  cout << ans;

  return 0;
}
