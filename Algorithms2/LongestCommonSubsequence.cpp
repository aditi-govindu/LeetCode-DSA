/*
Q300. Description: Longest Common subsequence problem
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int lenLCS[m+1][n+1];
        // Initialize 1st row and 1st column to 0
        for(int i = 0; i <= m; i++)
            lenLCS[i][0] = 0;
        for(int j = 0; j <= n; j++)
            lenLCS[0][j] = 0;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // If character in strings are equal, update DP array by adding 1 to previous cell
                if(text1[i-1] == text2[j-1])
                    lenLCS[i][j] = lenLCS[i-1][j-1] + 1;
                else
                    // Update cell to max of diagonals
                    lenLCS[i][j] = max(lenLCS[i-1][j], lenLCS[i][j-1]);
            }
        }
        // Last cell contains solution
        return lenLCS[m][n];
    }
};