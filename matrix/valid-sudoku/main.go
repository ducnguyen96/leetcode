package main

func isValidSudoku(board [][]byte) bool {
	rows := [9]map[byte]bool{}
	cols := [9]map[byte]bool{}
	boxes := [9]map[byte]bool{}

	for i := 0; i < 9; i++ {
		rows[i] = map[byte]bool{}
		cols[i] = map[byte]bool{}
		boxes[i] = map[byte]bool{}
	}

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				num := board[i][j]
				box := i/3*3 + j/3
				if _, ok := rows[i][num]; ok {
					return false
				} else {
					rows[i][num] = true
				}
				if _, ok := cols[j][num]; ok {
					return false
				} else {
					cols[j][num] = true
				}
				if _, ok := boxes[box][num]; ok {
					return false
				} else {
					boxes[box][num] = true
				}
			}
		}
	}

	return true
}
