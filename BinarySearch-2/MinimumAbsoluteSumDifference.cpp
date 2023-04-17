/*
Q1818. Description: You are given two positive integer arrays nums1 and nums2, both of length n.

The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).

You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.

Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.

|x| is defined as:

x if x >= 0, or
-x if x < 0.
*/

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& n1, vector<int>& n2) 
    {
        long res = 0, gain = 0;
        set<int> s(begin(n1), end(n1));
        
        for (int i = 0; i < n1.size(); ++i) 
        {
            long original = abs(n1[i] - n2[i]);
            res += original;

            if (gain < original) 
            {
                auto it = s.lower_bound(n2[i]);
                //  Track the biggest gain between original and replace value among all numbers
                if (it != end(s))
                    gain = max(gain, original - abs(*it - n2[i]));
                if (it != begin(s))
                    gain = max(gain, original - abs(*prev(it) - n2[i]));
            }
        }
        return (res - gain) % 1000000007;
    }
};