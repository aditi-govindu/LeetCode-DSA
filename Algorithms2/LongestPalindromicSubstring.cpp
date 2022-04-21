/*
Q5. Description: Given a string s, return the longest palindromic substring in s.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 1)
            return "";
        int start = 0; int end = 0;
        for(int i = 0; i < s.length(); i++)
        {
            // Palindromes have a unique center and even no. of characters
            int len1 = ExpandCenter(s, i, i);
            int len2 = ExpandCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, (end-start)+1);
    }
    
    int ExpandCenter(string s, int left, int right)
    {
        int L = left, R = right;
        // If characters are equal, consider the characters and reduce window size
        while( L >= 0 && R < s.length() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};