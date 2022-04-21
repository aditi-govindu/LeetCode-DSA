/*
Q209. Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

class Solution {
public:
   int minSubArrayLen(int s, vector<int>& nums)
   {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
       // Initialize solution array to 0
        vector<int> sums(n + 1, 0); 
       // Find sum of items in array
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            int to_find = s + sums[i - 1];
            // If sum is greater than target, add to list
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};