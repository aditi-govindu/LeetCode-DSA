/*
Q189. Rotate array 
Description: Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        int[] result = new int[n];
        // If k is a multiple of n or greater than n, get last digit only
        k = k%n;
        for(int i = 0; i < n; i++)
        {
            // New place is (current place + k)% length
            result[(i+k)%n] = nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            // Copy result into original array
            nums[i] = result[i];
        }
    }
}