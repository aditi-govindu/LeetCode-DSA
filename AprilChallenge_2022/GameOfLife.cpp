/*
Q289. Description: The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

* Any live cell with fewer than two live neighbors dies as if caused by under-population.
* Any live cell with two or three live neighbors lives on to the next generation.
* Any live cell with more than three live neighbors dies, as if by over-population.
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
*/

class Solution {
    // Move in 8 directions
    vector<vector<int>> moves = {
        {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };
    
public:
    int findNeighbours(vector<vector<int>>& board, int x, int y)
    {
        int alive = 0;
        for(auto& dir : moves)
        {
            int no_rows = x + dir[0];
            int no_cols = y + dir[1];
            // If row index out of range, go to next iteration
            if(no_rows < 0 || no_rows >= board.size())
                continue;
            // If column index out of range go to next iteration
            if(no_cols < 0 || no_cols >= board[0].size())
                continue;
            // Count no. of alive nodes
            alive += board[no_rows][no_cols];
        }
        return alive;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>> newBoard(rows, vector<int>(cols));
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int alive = findNeighbours(board, i, j);
                // Dead cell (0) with three live (1) neighbors becomes a live cell
                if(board[i][j] == 0 && alive == 3)
                    newBoard[i][j] = 1;
                // Any live cell with fewer than two live neighbors dies
                else if(board[i][j] == 1 && alive < 2)
                    newBoard[i][j] = 0;
                // Any live cell with more than three live neighbors dies
                else if(board[i][j] == 1 && alive > 3)
                    newBoard[i][j] = 0;
                // Any live cell with two-three live neighbors lives on.
                else if(board[i][j] == 1)
                    newBoard[i][j] = 1;
            }
        }
        board = newBoard;
    }
};