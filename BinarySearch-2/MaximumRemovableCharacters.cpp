/*
Q1898. Description: You are given two strings s and p where p is a subsequence of s. You are also given a distinct 0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed).

You want to choose an integer k (0 <= k <= removable.length) such that, after removing k characters from s using the first k indices in removable, p is still a subsequence of s. More formally, you will mark the character at s[removable[i]] for each 0 <= i < k, then remove all marked characters and check if p is still a subsequence.

Return the maximum k you can choose such that p is still a subsequence of s after the removals.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
*/

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        int i=0;
        int j=removable.size();
        int ans=0;

        while(i <= j)
        {
            int mid=i+(j-i)/2;
            string s1 = s;

            for(int i=0; i<mid; i++)
                s1[removable[i]]='A';

            int l=p.size(), k=0;
            for(int i=0; i<s1.size() && k<l; i++)
            {
                if(s1[i]==p[k])
                    k++;
            }
            
            if(l == k)
            {
                ans = mid;
                i = mid+1;
            }
            else
                j = mid-1;
        }
        return ans;
    }
};