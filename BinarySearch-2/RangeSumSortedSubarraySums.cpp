/*
Q1508. Description: You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.
*/

class Solution {
public:
    const int mod = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        int ans = 0;
        vector<int> sumSubArray;
        for(int i = 0; i < n; i++)
        {
            int k = 0;
            for(int j = i; j < n; j++)
            {
                k += nums[j];
                sumSubArray.push_back(k);
            }
        }
        sort(sumSubArray.begin(), sumSubArray.end());
        
        for(int i = left - 1; i <= right - 1; i++)
        {
            ans += sumSubArray[i];
            ans %= mod;
        }
        return ans;
    }
};