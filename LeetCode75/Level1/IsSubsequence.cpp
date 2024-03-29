/*
Q392. Description: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int j = 0;
        for(int i = 0; i < t.length(); i++)
        {
            // If character match found, advance s pointer
            if(s[j] == t[i])
                j++;
        }
        // If all characters in t found in s, return true
        return j == s.length();
    }
};