/*
Q72. Description: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word: Insert, Delete and Replace
Eg: horse and ros
Sol: Take horse
     rorse -> replace h
     rose -> remove r
     ros -> remove e
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // Dynamic programming array
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return Solve(n-1, m-1, word1, word2, dp);
    }
    
    int Solve(int i,int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        if(dp[i][j] != -1)
            return dp[i][j];
        // If characters match, return count as is
        if(word1[i] == word2[j])
            return dp[i][j] = Solve(i-1, j-1, word1, word2, dp);
        char c = word1[i];
        word1[i] = word2[j];
        // Replace character and move in both strings
        int rep = 1 + Solve(i-1, j-1, word1, word2, dp);
        word1[i] = c;
        // Delete charcater in 1 string
        int del = 1 + Solve(i-1, j, word1, word2, dp);
        // Insert in string
        int insert = 1 + Solve(i, j-1, word1, word2, dp);
        // Store minimum value out of all operations
        return dp[i][j] = min(rep, min(del,insert));    
    }
};