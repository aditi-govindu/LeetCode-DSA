/*
Q1712. Description: A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
*/

class Solution 
{
    public int waysToSplit(int[] nums) 
    {
        int sz = nums.length, res = 0;

        // Compute prefix sum of array
        for (int i = 1; i < sz; ++i)
            nums[i] += nums[i - 1];
        
        // Find optimal subarrays in prefix
        for (int i = 0, j = 0, k = 0; i < sz - 2; ++i) 
        {
            while (j <= i || (j < sz - 1 && nums[j] < nums[i] * 2))
                ++j;
            while (k < j || ( k < sz - 1 && nums[k] - nums[i] <= nums[sz - 1] - nums[k]))
                ++k;
            res = (res + k - j) % 1000000007;
        }    
        return res;
    }
}