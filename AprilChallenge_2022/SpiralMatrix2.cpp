/*
Q59. Description: Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order. Eg: for n = 3

1 -> 2 -> 3
          |
8 -> 9    4
|         |
7 <- 6 <- 5

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n));
        int count = 1;
        for(int i = 0; i < (n + 1)/2; i++)
        {
            // Travel left to right and insert 1,2,3...
            for(int j = i; j < n-i; j++)
                result[i][j] = count++;
            // Travel down in last column, incrementing row
            for(int k = i+1; k < n-i; k++)
                result[k][n-i-1] = count++;
            // Travel right to left in last row, increment column
            for(int l = n-i-2; l >= i; l--)
                result[n - i - 1][l] = count++;
            // Travel up in first column, incrementing row
            for(int m = n-i-2; m > i; m--)
                result[m][i] = count++;
        }
        return result;
    }
};