#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  void dfs(vector<vector<char>> &board, int rows, int cols, int row, int col) {
    if (row < 0 || row > rows - 1 || col < 0 || col > cols - 1 ||
        board[row][col] != 'O') {
      return;
    }
    board[row][col] = '*';
    for (auto [dr, dc] : directions) {
      dfs(board, rows, cols, row + dr, col + dc);
    }
  }
  void solve(vector<vector<char>> &board) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
      if (board[i][0] == 'O') {
        dfs(board, rows, cols, i, 0);
      }
      if (board[i][cols - 1] == 'O') {
        dfs(board, rows, cols, i, cols - 1);
      }
    }

    for (int i = 0; i < cols; i++) {
      if (board[0][i] == 'O') {
        dfs(board, rows, cols, 0, i);
      }
      if (board[rows - 1][i] == 'O') {
        dfs(board, rows, cols, rows - 1, i);
      }
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (board[i][j] == '*') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
