/*
Q413. Description: An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        int index = 0;
        if(nums.size() < 3)
            return 0;
        // Store difference of first 2 terms
        int prev_diff = nums[1] - nums[0];
        for(int i = 1; i < nums.size() - 1; i++)
        {
            // If previous difference is equal to current, increment count
            int diff = nums[i + 1] - nums[i];
            if(diff == prev_diff)
                ++index;
            else
            {
                // Not equal, update new difference and reset count
                prev_diff = diff;
                index = 0;
            }
            count += index;
        }
        return count;
    }
};