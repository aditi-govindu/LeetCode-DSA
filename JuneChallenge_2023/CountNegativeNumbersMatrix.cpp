/* Q1351. Description: Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] < 0)
                    count++;
            }
        }
        return count;
    }
};