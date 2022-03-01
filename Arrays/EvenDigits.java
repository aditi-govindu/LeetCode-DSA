/*
Description: Given an array nums of integers, return how many of them contain an even number of digits.
*/

// Q2. Find even digit numbers in array of numbers
class Solution {
    public int findNumbers(int[] nums) {
        int even = 0;
        for(int i = 0; i < nums.length; i++)
        {
            // Retrieve number from array
            int num = nums[i];
            int count = 0;
            // Get digits in every number
            while(num > 0)
            {
                int digit = num%10;
                count++;
                num = num/10;
            }
            // If count of digits is even, increment even
            if(count%2 == 0)
                even++;
        }
        return even; 
    }
}