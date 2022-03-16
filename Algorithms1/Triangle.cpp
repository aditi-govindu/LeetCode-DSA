/*
Q120. Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Bottom up approach
        int n = triangle.size();
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                int val = triangle[i+1][j];
                // Add minimum value of current value and previous value to triangle
                triangle[i][j] += min(val, triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};