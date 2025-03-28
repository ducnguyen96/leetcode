from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rows, cols = len(matrix), len(matrix[0])
        row, rowStart, rowEnd, col, colStart, colEnd = 0, 0, rows - 1, 0, 0, cols - 1
        direction = 1

        ans = []

        for _ in range(rows * cols):
            ans.append(matrix[row][col])

            match direction:
                case 1:
                    if col == colEnd:
                        rowStart += 1
                        row = rowStart
                        direction = 2
                    else:
                        col += 1
                case 2:
                    if row == rowEnd:
                        colEnd -= 1
                        col = colEnd
                        direction = 3
                    else:
                        row += 1
                case 3:
                    if col == colStart:
                        rowEnd -= 1
                        row = rowEnd
                        direction = 4
                    else:
                        col -= 1
                case 4:
                    if row == rowStart:
                        colStart += 1
                        col = colStart
                        direction = 1
                    else:
                        row -= 1
        return ans
