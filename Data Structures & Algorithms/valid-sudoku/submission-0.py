class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # most likely need row, col, and grid freq
        # brute force is checking all the rows, checking all the cols, and then all the grids
        # however we can do this stuff at the same time (in just one pass)
        # save as tuples (row/col/grid, num) -> freq

        row_freq = {}
        col_freq = {}
        grid_freq = {}
        # also want a coord to grid function
        for i in range(9):
            for j in range(9):
                grid_num = (i // 3) * 3 + (j // 3)
                # handle the "." case
                if board[i][j] != ".":
                    row_freq[(i, board[i][j])] = row_freq.get((i, board[i][j]), 0) + 1
                    col_freq[(j, board[i][j])] = col_freq.get((j, board[i][j]), 0) + 1
                    grid_freq[(grid_num, board[i][j])] = grid_freq.get((grid_num, board[i][j]), 0) + 1
                # coord to grid
                    if row_freq[(i, board[i][j])] > 1 or col_freq[(j, board[i][j])] > 1 or grid_freq[(grid_num, board[i][j])] > 1:
                        print((i, j, grid_num, board[i][j]))
                        print(row_freq[(i, board[i][j])], col_freq[(j, board[i][j])], grid_freq[(grid_num, board[i][j])])
                        return False

        return True