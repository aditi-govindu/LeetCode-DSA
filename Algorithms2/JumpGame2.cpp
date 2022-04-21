/*
Q45. Description: Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_max = 0;
        int next_max = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            // If end of array reached, return count
            if(curr_max == nums.size()-1)
                return count;
            next_max = max(i+nums[i], next_max);
            if(i == curr_max)
            {
                // If index is equal to next max, update current max
                curr_max = next_max;
                count++;
            }
        }
        return count;
    }
};