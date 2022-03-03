/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.
*/

// Q12. Place even numbers to front of array and odd to end of array
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int j = 0;
        for(int i = 0; i < nums.length; i++)
        {
            // If number is even, swap with its neighbour
            if(nums[i]%2 == 0)
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }
       return nums; 
    }
}