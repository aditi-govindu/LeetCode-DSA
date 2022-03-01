/*
Description: Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

// Import modules
import java.io.*;  
import java.Lang.Math;


// Q1. Find longest consecutive series of 1s in an array {0,1}
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) 
    {
        int len = nums.length;
        int longest = 0;
        int currlength = 0;
        
        if(len <= 0)
            return 0;

        for(int i = 0; i < len; i++)
        {
            // Store current length of 1's seen
            if(nums[i] == 1)
            {
                currlength++;
            }
            else
            {
                // Reset current length when 0 is seen
                currlength = 0;
            }
            // Store maximum length of 1's seen
            longest = Math.max(currlength, longest);
        }
        return longest;
    }
}