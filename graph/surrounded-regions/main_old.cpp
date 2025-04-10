#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  void bfs(vector<vector<char>> &board, vector<vector<bool>> visited, int rows,
           int cols, int row, int col) {
    vector<pair<int, int>> q = {{row, col}};

    int idx = 0;
    bool boarded = false;

    while (idx < q.size()) {
      auto [nr, nc] = q[idx];
      if (nr == 0 || nr == rows - 1 || nc == 0 || nc == cols - 1) {
        boarded = true;
        idx++;
        continue;
      }

      for (auto [dr, dc] : directions) {
        int r = nr + dr;
        int c = nc + dc;
        if (board[r][c] == 'O' && !visited[r][c]) {
          q.push_back({r, c});
          visited[r][c] = true;
        }
      }

      idx++;
    }

    if (!boarded) {
      for (auto [nr, nc] : q) {
        board[nr][nc] = 'X';
      }
    }
  }
  void solve(vector<vector<char>> &board) {
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 1; i < rows - 1; i++) {
      for (int j = 1; j < cols - 1; j++) {
        if (board[i][j] == 'X' || visited[i][j]) {
          continue;
        }
        bfs(board, visited, rows, cols, i, j);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  // vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
  //                               {'X', 'O', 'O', 'X'},
  //                               {'X', 'X', 'O', 'X'},
  //                               {'X', 'O', 'X', 'X'}};

  // vector<vector<char>> board = {
  //     {'X', 'X', 'X', 'X'},
  //     {'X', 'O', 'O', 'X'},
  //     {'X', 'X', 'O', 'X'},
  //     {'X', 'O', 'X', 'X'},
  // };

  // vector<vector<char>> board = {
  //     {'O', 'O', 'O'},
  //     {'O', 'O', 'O'},
  //     {'O', 'O', 'O'},
  // };

  // vector<vector<char>> board = {{'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O',
  // 'O'},
  //                               {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O',
  //                               'X'},
  //                               {'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O',
  //                               'X'},
  //                               {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O',
  //                               'O'},
  //                               {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
  //                               'X'},
  //                               {'X', 'X', 'O', 'O', 'X', 'O', 'X', 'O',
  //                               'X'},
  //                               {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O',
  //                               'O'},
  //                               {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O',
  //                               'O'},
  //                               {'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O',
  //                               'O'}};

  vector<vector<char>> board = {
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O',
       'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'X', 'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O',
       'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O'},
      {'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O',
       'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X',
       'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
       'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
      {'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'O'},
      {'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X',
       'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
       'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}};

  sol->solve(board);

  for (auto row : board) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}
