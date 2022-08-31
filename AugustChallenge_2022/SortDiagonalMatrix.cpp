/*
Q1329. Description: A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        
        // Sort diagonal starting at row 0
        for(int i = 0; i < m; i++)
        {
            int row = i;
            int col = 0;
            vector<int> arr;
            
            while(row < m && col < n)
            {
                // Push diagonal elements into array and sort
                arr.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(arr.begin(), arr.end());
            row--;
            col--;
            
            while(row >= 0 && col >= 0)
            {
                // Fill matrix from bottom to top using sorted arr
                mat[row][col] = arr.back();
                arr.pop_back();
                row--;
                col--;
            }
        }
        
        // Sort diagonal starting at row 1
        for(int i = 1; i < n; i++)
        {
            int row = 0;
            int col = i;
            vector<int> arr;
            
            while(row < m && col < n)
            {
                // Push diagonal elements into array and sort
                arr.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(arr.begin(), arr.end());
            row--;
            col--;
            
            while(row >= 0 && col >= 0)
            {
                // Fill matrix from bottom to top using sorted arr
                mat[row][col] = arr.back();
                arr.pop_back();
                row--;
                col--;
            }
        }
        return mat;
    }
};