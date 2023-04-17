/*
Q35. Description: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution 
{
    public int searchInsert(int[] nums, int target) 
    {
        int start = 0;
        int end = nums.length - 1;
        int mid = 0;
        
        // Binary search for element
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        // If number needed is smaller than the array limits, place element at start
        if(nums[mid] < target)
            return start;
        return mid;
    }
}