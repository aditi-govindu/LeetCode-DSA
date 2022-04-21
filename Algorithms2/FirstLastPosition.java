/*
Q34. Description: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
    public int[] searchRange(int[] nums, int target)
    {
        int[] result = {-1,-1};
        // Get index of starting position in nums array
        result[0] = helper(nums,target,true);
        // If element not found, return {-1,-1} as it is
        if(result[0] != -1)
            result[1] = helper(nums,target,false);
        return result;
    }
    
    public int helper(int[] nums, int target, boolean find) {
        int index = -1;
        int start = 0;
        int end = nums.length - 1;
        // Binary search for element start index
        while(start <= end)
        {
            int mid = start + (end-start) / 2;
            if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] < target)
                start = mid + 1;
            else
            {
                // Element is found at midpoint, set start and end index for result[0]
                index = mid;
                if(find)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return index;
    }
}