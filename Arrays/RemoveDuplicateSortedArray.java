/*
Description: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
*/
// Q7. Remove duplicates in sorted array - Inplace
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for(int j = 1; j < nums.length; j++)
        {
            // Number is not equal to neighbour, store it in the array, starting with index i = 0
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        // Return count of unique numbers
        return i+1;
    }
}