/*
Q1498. Description: You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        // Total possible subsequences are 2^n
        vector<int> twopower{1};
        const int mod = 1e9 + 7;

        for(int i = 0; i < nums.size(); i++)
            twopower.push_back((twopower.back() * 2) % mod);
        
        sort(nums.begin(), nums.end());
        int ans= 0;

        int start = 0;
        int end = nums.size() - 1;

        while(start <= end)
        {
            // Reduce window size when target exceeded
            if(nums[start] + nums[end] > target)
                end--;
            else
            {
                // Found a pair, check for all subsequences that have this number + remainder
                int rem = end - start;
                
                ans = (ans + twopower[rem]) % mod;
                start++;
            }
        }
        return ans;
    }
};