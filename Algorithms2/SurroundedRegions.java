/*
Q130. Description: Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/

class Solution 
{
    public void DFS(char[][] board, int x, int y)
    {
        // Check if x and y are within the matrix
        if(x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] != 'O')
            return;
        board[x][y] = '$';
        // Explore all 4 directions - Up, down, left, right
        DFS(board, x+1, y);
        DFS(board, x-1, y);
        DFS(board, x, y-1);
        DFS(board, x, y+1);
    }
    
    public void solve(char[][] board) 
    {
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                // Replace neighbours of O by X using DFS search
                if(i == 0 || i == board.length-1 || j == 0 || j == board[0].length-1) 
                {
                    if(board[i][j] == 'O');
                        DFS(board, i, j);
                }
            }
        }
        
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                // Check for edge cases of O and replace by X
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                // Check for cells that are not affected and replace by O
                if(board[i][j] == '$')
                    board[i][j] = 'O';   
            }
        }
    }
}