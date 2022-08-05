/*
Q1365. Description: Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> results;
        for(int i = 0;  i < size(nums); i++)
        {
            int count = 0;
            for(int j = 0;  j < size(nums); j++)
            {
                // Brute force to compare every element to its neighbour
                if((nums[i] > nums[j]) && (i != j))
                    count++;
            }
            results.push_back(count);
        }
        return results;
    }
};