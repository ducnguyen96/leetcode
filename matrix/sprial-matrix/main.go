package main

func spiralOrder(matrix [][]int) []int {
	rows := len(matrix)
	cols := len(matrix[0])
	n := rows * cols

	row := 0
	rowStart := 0
	rowEnd := rows - 1

	col := 0
	colStart := 0
	colEnd := cols - 1

	direction := 1

	ans := []int{}

	for i := 0; i < n; i++ {
		ans = append(ans, matrix[row][col])

		switch direction {
		case 1:
			if col == colEnd {
				rowStart++
				row = rowStart
				direction = 2
			} else {
				col++
			}
			break
		case 2:
			if row == rowEnd {
				colEnd--
				col = colEnd
				direction = 3
			} else {
				row++
			}
			break
		case 3:
			if col == colStart {
				rowEnd--
				row = rowEnd
				direction = 4
			} else {
				col--
			}
			break
		default:
			if row == rowStart {
				colStart++
				col = colStart
				direction = 1
			} else {
				row--
			}
		}
	}

	return ans
}
