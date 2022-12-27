/*
Q118. Description: Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown
*/

class Solution {
public:
    int binomial_coef(int n, int k)
    {
        // Find binomial coefficient of every term in (x+y)^n nCk
        int res = 1;
        if(k > n)
            k = n-k;
        for(int i = 0; i < k; i++)
        {
            res = res * (n-i);
            res = res / (i+1);
        }
        return res;
    }
    
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++)
        {
            // For every row, find coefficient for k = 0,1...row number
            vector<int> temp;
            for(int j = 0; j <= i; j++)
                temp.push_back(binomial_coef(i,j));
            result.push_back(temp);
        }
        return result;
    }
};