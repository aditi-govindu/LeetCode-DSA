/*
Q55. Description: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

class Solution {
    public boolean canJump(int[] nums) 
    {
        int destination = nums.length - 1;
        // Iterate over the array in reverse order
        for(int i = nums.length - 2; i >= 0; i--)
        {
            // If current index + value is greater than destination, move destination ahead
            if(i + nums[i] >= destination)
                destination = i;   
        }
        // If start of array reached, return true
        return(destination == 0);
    }
}