/*
Q31. Description: A permutation of an array of integers is an arrangement of its members into a sequence or linear order. The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order). Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // Find first valley (number just after largest) number in series
        while(i >= 0 && nums[i + 1] <= nums[i])
        {
            i--;
        }
        if(i >= 0)
        {
            // Find number slightly larger than valley and swap
            int j = nums.size() - 1;
            while(nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums, i, j);
        }
        // Reverse all numbers after swapped index
        reverse(nums, i+1);
    }
    
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void reverse(vector<int>& nums, int start)
    {
        int i = start;
        int j = nums.size() - 1;
        while(i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
};