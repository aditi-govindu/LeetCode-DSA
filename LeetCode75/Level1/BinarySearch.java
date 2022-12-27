/*
Q704. Description: Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
    public int search(int[] nums, int target) 
    {
        int start = 0;
        int end = nums.length - 1;
        int mid = 0;

        while(start <= end)
        {
            // If element found at middle, return index
            mid = (start + end)/2;
            if(target == nums[mid])
                return mid;
            // If number is greater than middle, search in upper half
            else if(target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        // Element not found anywhere in list
        return -1;
    }
}