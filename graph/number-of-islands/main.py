from typing import List


class Solution:
    def dfs(self, grid: List[List[str]], rows: int, cols: int, row: int, col: int):
        if row < 0 or col < 0 or row >= rows or col >= cols or grid[row][col] == "0":
            return
        grid[row][col] = "0"
        self.dfs(grid, rows, cols, row - 1, col)
        self.dfs(grid, rows, cols, row + 1, col)
        self.dfs(grid, rows, cols, row, col - 1)
        self.dfs(grid, rows, cols, row, col + 1)

    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        ans = 0

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "0":
                    continue
                ans += 1
                self.dfs(grid, rows, cols, row, col)

        return ans
