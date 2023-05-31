/*
Q1035. Description: You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.
*/

class Solution {
public:
    int solve(int i, int j,vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& memo)
    {
        if(i < 1 || j < 1)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        // If line can be drawn, increment current count by 1
        if(nums1[i - 1] == nums2[j - 1])
            memo[i][j] = 1 + solve(i - 1, j - 1, nums1, nums2, memo);
        // Store maximum of count by comparing previous row and column values
        else
            memo[i][j] = max(solve(i,j-1,nums1,nums2,memo), solve(i-1,j,nums1,nums2,memo));
        return memo[i][j];
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(n1, n2, nums1, nums2, memo);
    }
};