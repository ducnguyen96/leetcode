function spiralOrder(matrix: number[][]): number[] {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const n = rows * cols;

  let row = 0;
  let rowStart = 0;
  let rowEnd = rows - 1;

  let col = 0;
  let colStart = 0;
  let colEnd = cols - 1;

  let direction = 1;

  const ans: number[] = [];

  for (let i = 0; i < n; i++) {
    ans.push(matrix[row][col]);
    switch (direction) {
      case 1:
        if (col == colEnd) {
          rowStart++;
          row = rowStart;
          direction = 2;
        } else {
          col++;
        }
        break;
      case 2:
        if (row == rowEnd) {
          colEnd--;
          col = colEnd;
          direction = 3;
        } else {
          row++;
        }
        break;
      case 3:
        if (col == colStart) {
          rowEnd--;
          row = rowEnd;
          direction = 4;
        } else {
          col--;
        }
        break;
      default:
        if (row == rowStart) {
          colStart++;
          col = colStart;
          direction = 1;
        } else {
          row--;
        }
        break;
    }
  }

  return ans;
}
