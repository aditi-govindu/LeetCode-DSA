'''
Q36. Description: Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 
'''
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        # Given an arr of row/col/sub, check if there are duplicates.
        def isValid(arr):
            s = ''.join(arr).replace('.','')
            return len(s) == len(set(s))
        
        # Check each row in the board
        def checkRow():
            for row in board:
                if not isValid(row):
                    return False
            return True
        
        # Check each col in the board,
        # To access each col, we first unpack the board into sperate lists using *
        # We then zip these rows together into columns.
        def checkCol():
            for col in zip(*board):
                if not isValid(col):
                    return False
            return True
        
        # To get each sub-box, we first get the top-left indices of each sub-box,
        # We then go 3 steps on each row and 3 steps on each col to construct the box.
        def checkSub():
            for r in range(0,9,3):
                for c in range(0,9,3):
                    sub = [board[r+dr][c+dc] for dr in range(3) for dc in range(3)]
                    if not isValid(sub):
                        return False
            return True
        
        # In order to be a valid Sudoku, all row, col, and sub-box need to be valid
        return checkRow() and checkCol() and checkSub()
            