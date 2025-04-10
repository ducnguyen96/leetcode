package main

var directions = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

func dfs(board [][]byte, rows int, cols int, row int, col int) {
	if row < 0 || col < 0 || row > rows-1 || col > cols-1 || board[row][col] != 'O' {
		return
	}
	board[row][col] = '*'
	for _, dir := range directions {
		dfs(board, rows, cols, row+dir[0], col+dir[1])
	}
}

func solve(board [][]byte) {
	rows := len(board)
	cols := len(board[0])

	for i := 0; i < rows; i++ {
		if board[i][0] == 'O' {
			dfs(board, rows, cols, i, 0)
		}
		if board[i][cols-1] == 'O' {
			dfs(board, rows, cols, i, cols-1)
		}
	}

	for i := 0; i < cols; i++ {
		if board[0][i] == 'O' {
			dfs(board, rows, cols, 0, i)
		}
		if board[rows-1][i] == 'O' {
			dfs(board, rows, cols, rows-1, i)
		}
	}

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			switch board[i][j] {
			case '*':
				board[i][j] = 'O'
			case 'O':
				board[i][j] = 'X'
			}
		}
	}
}
