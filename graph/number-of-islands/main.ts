function dfs(
  grid: string[][],
  rows: number,
  cols: number,
  row: number,
  col: number,
) {
  if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == "0")
    return;

  grid[row][col] = "0";
  dfs(grid, rows, cols, row - 1, col);
  dfs(grid, rows, cols, row + 1, col);
  dfs(grid, rows, cols, row, col - 1);
  dfs(grid, rows, cols, row, col + 1);
}

function numIslands(grid: string[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;
  let ans = 0;

  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      if (grid[row][col] == "0") continue;
      ans++;
      dfs(grid, rows, cols, row, col);
    }
  }

  return ans;
}
