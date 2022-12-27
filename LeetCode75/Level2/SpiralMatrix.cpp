/*
Q54. Description: Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int>spiral;
        
        int left = 0;
        int right = col - 1;
        int top = 0;
        int bottom = row - 1;
        int direction = 1;
        
        while(top <= bottom && left <= right)
        {
            switch(direction)
            {
                case 1: for(int i = left; i <=right; i++)
                            spiral.push_back(matrix[top][i]);
                        direction = 2;
                        top++;
                        break;
                case 2:for(int i = top; i <= bottom; i++)
                            spiral.push_back(matrix[i][right]);
                        direction = 3;
                        right--;
                        break;
                case 3:for(int i = right; i >= left; i--)
                            spiral.push_back(matrix[bottom][i]);
                        direction = 4;
                        bottom--;
                        break;
                case 4:for(int i = bottom; i >= top; i--)
                            spiral.push_back(matrix[i][left]);
                        direction = 1;
                        left++;
                        break;
            }
        }
        return spiral;
    }
};