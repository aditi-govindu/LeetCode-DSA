/*
Q300. Description: Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 

For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> longest(nums.size(), 1);
        int ans = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                // Dynamic programming array keeps track of current length, new length
                if(nums[i] > nums[j])
                    longest[i] = max(longest[i], longest[j]+1); 
            }
            ans = max(ans, longest[i]);
        }
        return ans;
    }
};