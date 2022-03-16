/*
Q283. Description: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note: Do this in-place without making a copy of the array.
*/

// Q11. Place all zeroes to end of array - Quicksort type
class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for(int i = 0; i < nums.length; i++)
        {
            // If element is not 0, swap with neighbour till 0 sinks to last place
            if(nums[i] != 0)
            {
                // Swap element with neighbour
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
            else
                continue;
        }
    }
}