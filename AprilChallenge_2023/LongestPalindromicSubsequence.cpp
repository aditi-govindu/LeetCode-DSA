/*
Q516. Description: Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/

class Solution {
public:
    int LCS(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        int lenLCS[m+1][n+1];
        
        // Longest common subsequence initialization of row 1 and column 1
        for(int i = 0; i <= m; i++)
            lenLCS[i][0] = 0;
        for(int j = 0; j <= n; j++)
            lenLCS[0][j] = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // Character matched, increment count of palindrome subsequence
                if(text1[i-1] == text2[j-1])
                    lenLCS[i][j] = lenLCS[i-1][j-1] + 1;
                else
                    lenLCS[i][j] = max(lenLCS[i-1][j], lenLCS[i][j-1]);
            }
        }
        return lenLCS[m][n];
    }
    
    int longestPalindromeSubseq(string s) 
    {
        string copy = s;
        reverse(s.begin(), s.end());
        return LCS(copy, s);
    }
};