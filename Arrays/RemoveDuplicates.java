/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
*/
// Q6. Remove duplicates in same array - Inplace
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.length; j++)
        {
            // Number is not repeated, store it in the array, starting with index i = 0
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        // Return count of unique numbers
        return i;
    }
}