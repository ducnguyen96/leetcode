package main

func dfs(grid [][]byte, rows int, cols int, row int, col int) {
	if row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == '0' {
		return
	}
	grid[row][col] = '0'
	dfs(grid, rows, cols, row-1, col)
	dfs(grid, rows, cols, row+1, col)
	dfs(grid, rows, cols, row, col-1)
	dfs(grid, rows, cols, row, col+1)
}

func numIslands(grid [][]byte) int {
	rows := len(grid)
	cols := len(grid[0])
	ans := 0

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == '0' {
				continue
			}
			ans++
			dfs(grid, rows, cols, i, j)
		}
	}

	return ans
}
