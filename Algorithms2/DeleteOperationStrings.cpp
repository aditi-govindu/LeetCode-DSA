class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int lenLCS[m+1][n+1];
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                // Initialize 1st row and 1st column to 0
                if(i == 0 || j == 0)
                    lenLCS[i][j] = i+j;
                // Characters are equal, update DP array by adding 1 to previous cell
                else if(word1[i-1] == word2[j-1])
                    lenLCS[i][j] = lenLCS[i-1][j-1];
                else
                    // Update cell to min of diagonals
                    lenLCS[i][j] = 1+ min(lenLCS[i-1][j], lenLCS[i][j-1]);
            }
        }
        // Last cell contains solution
        return lenLCS[m][n];

    }
};