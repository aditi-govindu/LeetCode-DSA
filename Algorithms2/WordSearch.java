/*
Q79. Description: Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

class Solution {
    // 4 directions to search are Down, Up, Left and Right
    int[] dir_x = {0,1,0,-1};
    int[] dir_y = {1,0,-1,0}; 
    
    public boolean DFS(char[][] board, int x, int y, int idx, String word)
    {
        // Reached end of word, return true
        if(idx == word.length())
            return true;
        // Matrix out of bounds, return false
        if(x < 0 || x >= board.length || y < 0 || y >= board[0].length)
            return false;
        // Charcater not found, return false
        if(board[x][y] != word.charAt(idx))
            return false;
        char c = board[x][y];
        board[x][y] = '#';
        // Travel in 4 directions - Up, Down, Left and Right to search for characters
        for(int i = 0; i < 4; i++)
        {
            boolean ans = DFS(board, x + dir_x[i], y + dir_y[i], idx+1, word);
            // Letter matches, return true
            if(ans)
            {
                board[x][y] = c;
                return true;
            }
        }
        // Character not found, set board back to character and return false
        board[x][y] = c;
        return false; 
    }
    
    public boolean exist(char[][] board, String word) {
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                // If character found, start DFS search
                if(board[i][j] == word.charAt(0))
                {
                    boolean sol = DFS(board, i, j, 0, word);
                    if(sol)
                        return true;
                }
            }
        }
        return false;
    }
}