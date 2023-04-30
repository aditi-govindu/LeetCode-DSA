/*
Q1768. Description: You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        string merged = "";

        if(n < m)
        {
            // Copy letters alternately from each string
            int i;
            for(i = 0; i < n; i++)
                merged = merged + word1[i] + word2[i];

            // Copy leftover string 
            for(int j = i; j < m; j++)
                merged += word2[j];
        }
        else
        {
            int i;
            for(i = 0; i < m; i++)
                merged = merged + word1[i] + word2[i];
                
            for(int j = i; j < n; j++)
                merged += word1[j];
        }
        return merged;
    }
};